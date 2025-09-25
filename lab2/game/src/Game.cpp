#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
using namespace std;

void Game::Init() {
    world.Generate();
    // preload shop goods (avoid initializer_list to sidestep ASan quirk)
    shopGoods.clear(); shopGoods.reserve(5);
    shopGoods.emplace_back("Small Potion", 5);
    shopGoods.emplace_back("Mana Potion", 8);
    shopGoods.emplace_back("Level Potion", 50);
    shopGoods.emplace_back("Upgrade Potion", 25);
    shopGoods.emplace_back("Rusty Dagger", 8);
    shopGoods.emplace_back("Goblin Ear", 1);
    // Give player starting potion
    player.AddItem("Small Potion");
    cout << "Game started! Type 'help' for help." << endl;
}

void Game::ShowShop() {
    cout << "Merchant goods:" << endl;
    for (const auto& g : shopGoods) cout << "- " << g.first << " (" << g.second << "g)" << endl;
    cout << "Use: buy <item> | sell <item>" << endl;
}

void Game::BuyItem(const std::string& name) {
    for (const auto& g : shopGoods) {
        if (g.first == name) {
            if (player.GetGold() >= g.second) {
                player.AddGold(-g.second);
                player.AddItem(name);
                cout << "Purchase completed." << endl;
            } else {
                cout << "Not enough gold." << endl;
            }
            return;
        }
    }
    cout << "Item not found." << endl;
}

void Game::SellItem(const std::string& name) {
    if (player.RemoveItemByName(name)) {
        int price = 1;
        for (const auto& g : shopGoods) if (g.first == name) { price = g.second / 2; break; }
        player.AddGold(price);
        cout << "Sale completed." << endl;
    } else {
        cout << "You don't have this item." << endl;
    }
}

void Game::Run() {
    bool running = true;
    string line;
    while (running && std::getline(cin, line)) {
        line = Utils::Trim(line);
        if (line.empty()) continue;
        if (Utils::ToLower(line) == "exit") { running = false; break; }
        if (gameFinished) { 
            cout << "Congratulations! You completed the game!" << endl;
            running = false; 
            break; 
        }
        HandleCommand(line);
    }
}

void Game::Render() {
    // text mode — output in command handlers
}

void Game::Update() {
    // placeholder for future world logic
}

void Game::Exit() {
    cout << "Game ended." << endl;
}

void Game::PrintHelp() {
    cout << "Available commands:\n"
            "help, look, move <north|south|east|west>, stats, inventory|inv,\n"
            "use <item>, equip <item>, drop <item>, upgrade, talk, trade\n";
    if (questCompleted) {
        cout << "Combat: attack <enemy>, defend, skill <name>, cast <spell>, use <item>, run\n";
    } else {
        cout << "Combat: attack <enemy>, defend, use <item>, run (skills unlock after quest)\n";
    }
    cout << "System: exit\n";
}

void Game::HandleCommand(const std::string& line) {
    auto parts = Utils::Split(line, ' ');
    if (parts.empty()) return;
    string cmd = Utils::ToLower(parts[0]);

    if (cmd == "help") { PrintHelp(); return; }
    if (cmd == "look") { world.Draw(); return; }
    if (cmd == "stats") { 
        cout << "=== PLAYER STATISTICS ===" << endl;
        cout << "HP: " << player.GetHP() << "/" << player.GetMaxHp() << endl;
        cout << "Mana: " << player.GetMana() << "/" << player.GetMaxMana() << endl;
        cout << "Level: " << player.GetLevel() << endl;
        cout << "Gold: " << player.GetGold() << endl;
        cout << "Equipped Weapon: " << player.GetEquipped() << endl;
        cout << "Equipped Armor: " << player.GetEquippedArmor() << endl;
        cout << "Equipped Artifact: " << player.GetEquippedArtifact() << endl;
        if (player.GetWeaponUpgrades() > 0) {
            cout << "Weapon Upgrades: " << player.GetWeaponUpgrades() << endl;
        }
        if (player.GetArmorUpgrades() > 0) {
            cout << "Armor Upgrades: " << player.GetArmorUpgrades() << endl;
        }
        if (player.GetArmorDefense() > 0) {
            cout << "Armor Defense: " << player.GetArmorDefense() << endl;
        }
        if (questCompleted) {
            cout << "\n=== AVAILABLE SKILLS ===" << endl;
            cout << "1. Power Strike - Strong attack (damage: 25)" << endl;
            cout << "\n=== AVAILABLE SPELLS ===" << endl;
            cout << "1. Fireball - Fireball (damage: 20, mana: 15)" << endl;
            cout << "2. Heal - Healing (restore: 15, mana: 10)" << endl;
            cout << "3. Lightning - Lightning (damage: 25, mana: 20)" << endl;
        } else {
            cout << "\nSkills and magic are locked. Complete the first quest!" << endl;
        }
        return; 
    }
    if (cmd == "inventory" || cmd == "inv") {
        auto describe = [](const std::string& name) -> std::string {
            if (name == "Goblin Ear") return "Trophy. +1 gold per kill when equipped.";
            if (name == "Small Potion") return "Consumable. Restores 20 HP.";
            if (name == "Mana Potion") return "Consumable. Restores 30 mana.";
            if (name == "Level Potion") return "Consumable. Increases level by 1.";
            if (name == "Upgrade Potion") return "Consumable. Upgrades equipped weapon or armor.";
            if (name == "Rusty Dagger") return "Weapon. Very low damage.";
            if (name == "Iron Sword") return "Weapon. Good damage.";
            if (name == "Leather Armor") return "Armor. Provides protection.";
            return "Unknown item.";
        };
        const auto& inv = player.GetInventory();
        if (inv.empty()) cout << "Inventory is empty." << endl;
        else {
            for (const auto& it : inv) {
                bool on = (!player.GetEquipped().empty() && player.GetEquipped() == it);
                cout << "- " << it << (on ? " (equipped)" : "") << " — " << describe(it) << '\n';
            }
        }
        return;
    }
    if (cmd == "move" && parts.size() >= 2) {
        if (inBattle) { cout << "You are in battle! You can only move with 'run' command." << endl; return; }
        string dir = Utils::ToLower(parts[1]);
        int dx = 0, dy = 0;
        if (dir == "north") dy = -1; else if (dir == "south") dy = 1; else if (dir == "west") dx = -1; else if (dir == "east") dx = 1;
        // prevent entering cells with objects (NPC/M/E/D)
        int tx = world.GetPlayerX() + dx;
        int ty = world.GetPlayerY() + dy;
        auto t = world.GetTile(tx, ty);
        if (t && (t->GetType() == 'N' || t->GetType() == 'M' || t->GetType() == 'E' || t->GetType() == 'D')) { cout << "Cell is occupied." << endl; return; }
        bool ok = world.MovePlayer(dx, dy);
        cout << (ok ? "You moved." : "Cannot move there.") << endl;
        // after player turn — enemy turn
        if (world.HasEnemy()) {
            if (world.DistToEnemy() <= 5) world.MoveEnemyTowardPlayer(); else world.MoveEnemyRandom();
            if (world.DistToEnemy() <= 1) {
                cout << "Enemy caught up! Battle begins." << endl;
                enemy = Enemy(); // reset enemy stats when engaging
                battle.Start(player, enemy, world);
                inBattle = true;
                battleEnemyX = world.GetEnemyX(); battleEnemyY = world.GetEnemyY();
            }
        }
        world.MoveExtraEnemies();
        int ex, ey; if (!inBattle && world.EngageAdjacentExtraEnemy(ex, ey)) {
            // move engaged extra enemy into main enemy slot and start battle
            world.SpawnEnemyAt(ex, ey);
            cout << "Enemy caught up! Battle begins." << endl;
            enemy = Enemy();
            battle.Start(player, enemy, world); inBattle = true; battleEnemyX = ex; battleEnemyY = ey;
        }
        if (bonusNoAttackTurns > 0) bonusNoAttackTurns = 0; // burn bonus turn for non-attacking command
        return;
    }

    // combat mode: if battle started — handle combat commands
    if (cmd == "attack") {
        if (!inBattle) { 
            battle.Start(player, enemy, world); 
            if (battle.IsActive()) {
                inBattle = true;
            }
        }
        battle.PlayerTurn();
        if (!battle.CheckWin()) { battle.EnemyTurn(); }
        if (battle.CheckWin()) {
            // enemy is dead — give loot
            if (enemy.IsDead()) {
                int baseGold = 10;
                // bonus from ears
                int bonus = (player.GetEquipped() == "Goblin Ear") ? 1 : 0;
                player.AddGold(baseGold + bonus);
                
                // Check if this is dragon or regular enemy
                if (world.HasDragon() && !world.IsDragonDefeated()) {
                    cout << "You defeated the mighty Dragon!" << endl;
                    secondQuestCompleted = true;
                    world.ClearMainEnemy();
                    world.ClearDragon(); // Remove dragon from map
                    world.SetDragonDefeated(true);
                    // Don't create new enemy object for dragon - dragon is permanently defeated
                } else {
                    static bool guaranteedEarPending = true;
                    if (guaranteedEarPending) { player.AddItem("Goblin Ear"); guaranteedEarPending = false; }
                    else {
                        int roll = Utils::RandomInt(1, 100);
                        if (roll <= 60) player.AddItem("Goblin Ear");
                        else if (roll <= 85) player.AddItem("Small Potion");
                        else player.AddItem("Rusty Dagger");
                    }
                    // Always give healing potion after first battle
                    player.AddItem("Small Potion");
                    // Create new enemy object only for regular enemies
                    enemy = Enemy();
                }
            }
            battle.End(); inBattle = false; world.ClearMainEnemy();
        }
        return;
    }
    if (cmd == "skill" && parts.size() >= 2) {
        if (!questCompleted) { cout << "Skills are locked. Complete the quest first." << endl; return; }
        std::string skill; for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) skill += ' '; skill += parts[i]; }
        UseSkill(skill);
        return;
    }
    if (cmd == "cast" && parts.size() >= 2) {
        if (!questCompleted) { cout << "Magic is locked. Complete the quest first." << endl; return; }
        std::string spell; for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) spell += ' '; spell += parts[i]; }
        CastSpell(spell);
        return;
    }
    if (cmd == "defend") {
        player.Defend();
        // After defending, player gets a bonus turn where they can attack
        // but enemy doesn't respond to the next action
        return;
    }
    if (cmd == "use" && parts.size() >= 2) {
        std::string item;
        for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) item += ' '; item += parts[i]; }
        item = Utils::Trim(item);
        if (item == "potion" || item == "Small Potion") {
            if (player.HasItem("Small Potion")) {
                player.Heal(20);
                player.RemoveItemByName("Small Potion");
                cout << "You used healing potion!" << endl;
                if (inBattle) {
                    if (bonusNoAttackTurns > 0) {
                        // bonus turn — enemy doesn't respond
                    } else {
                        if (!battle.CheckWin()) { battle.EnemyTurn(); }
                        if (battle.CheckWin()) { 
                            battle.End(); inBattle = false; 
                            world.ClearMainEnemy();
                            // Create new enemy object since the old one is dead and removed from map
                            enemy = Enemy();
                        }
                    }
                }
            } else {
                cout << "You don't have healing potion!" << endl;
            }
        } else if (item == "mana potion" || item == "Mana Potion") {
            if (player.HasItem("Mana Potion")) {
                player.RestoreMana(30);
                player.RemoveItemByName("Mana Potion");
                cout << "You used mana potion!" << endl;
            } else {
                cout << "You don't have mana potion!" << endl;
            }
        } else if (item == "level potion" || item == "Level Potion") {
            if (player.HasItem("Level Potion")) {
                player.LevelUp();
                player.RemoveItemByName("Level Potion");
                cout << "You used level potion!" << endl;
            } else {
                cout << "You don't have level potion!" << endl;
            }
        } else if (item == "upgrade potion" || item == "Upgrade Potion") {
            if (player.HasItem("Upgrade Potion")) {
                if (player.GetEquipped() == "Iron Sword" || player.GetEquipped() == "Rusty Dagger") {
                    // Upgrade weapon
                    player.RemoveItemByName("Upgrade Potion");
                    player.UpgradeWeapon();
                    cout << "You used Upgrade Potion on your weapon!" << endl;
                } else if (player.GetEquippedArmor() == "Leather Armor") {
                    // Upgrade armor
                    player.RemoveItemByName("Upgrade Potion");
                    player.UpgradeArmor();
                    cout << "You used Upgrade Potion on your armor!" << endl;
                } else {
                    cout << "You need to equip a weapon or armor to use Upgrade Potion!" << endl;
                    return;
                }
            } else {
                cout << "You don't have Upgrade Potion!" << endl;
            }
        } else {
            cout << "Unknown item: " << item << endl;
        }
        if (bonusNoAttackTurns > 0) bonusNoAttackTurns = 0;
        return;
    }
    if (cmd == "equip" && parts.size() >= 2) {
        std::string item;
        for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) item += ' '; item += parts[i]; }
        item = Utils::Trim(item);
        
        // Check item type and equip to appropriate slot
        if (item == "Leather Armor") {
            player.EquipArmor(item);
        } else if (item == "Iron Sword" || item == "Rusty Dagger") {
            if (!player.Equip(item)) {
                cout << "Failed to equip weapon: " << item << endl;
            }
        } else if (item == "Goblin Ear") {
            player.EquipArtifact(item);
        } else {
            cout << "Unknown item type: " << item << endl;
        }
        if (bonusNoAttackTurns > 0) bonusNoAttackTurns = 0;
        return;
    }
    if (cmd == "upgrade") {
        if (player.HasItem("Upgrade Potion")) {
            if (player.GetEquipped() == "Iron Sword" || player.GetEquipped() == "Rusty Dagger") {
                // Upgrade weapon
                player.RemoveItemByName("Upgrade Potion");
                player.UpgradeWeapon();
                cout << "You used Upgrade Potion on your weapon!" << endl;
            } else if (player.GetEquippedArmor() == "Leather Armor") {
                // Upgrade armor
                player.RemoveItemByName("Upgrade Potion");
                player.UpgradeArmor();
                cout << "You used Upgrade Potion on your armor!" << endl;
            } else {
                cout << "You need to equip a weapon or armor to use Upgrade Potion!" << endl;
            }
        } else {
            cout << "You don't have Upgrade Potion!" << endl;
        }
        if (bonusNoAttackTurns > 0) bonusNoAttackTurns = 0;
        return;
    }
    if (cmd == "run") {
        if (inBattle) { cout << "You try to run away... Success!" << endl; battle.End(); inBattle = false; bonusNoAttackTurns = 1; }
        else { cout << "Nothing to fear." << endl; }
        return;
    }

    // simple shop sub-commands (active while at merchant): buy <item>, sell <item>
    if (!parts.empty() && (cmd == "buy" || cmd == "sell")) {
        if (!world.IsNearMerchant() || !world.HasMerchant()) { cout << "You are not at merchant." << endl; return; }
        if (parts.size() < 2) { cout << (cmd == "buy" ? "Specify item." : "Specify item to sell.") << endl; return; }
        std::string item;
        for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) item += ' '; item += parts[i]; }
        item = Utils::Trim(item);
        if (cmd == "buy") BuyItem(item); else SellItem(item);
        return;
    }

    if (cmd == "talk") {
        if (inBattle) { cout << "Too dangerous to talk in battle." << endl; return; }
        // Check for main enemy nearby
        if (world.HasEnemy() && world.DistToEnemy() <= 5) { cout << "Too dangerous to talk near enemy." << endl; return; }
        // Check for extra enemies nearby
        int ex, ey;
        if (world.EngageAdjacentExtraEnemy(ex, ey)) {
            cout << "Extra enemy nearby! Battle begins." << endl;
            enemy = Enemy();
            battle.Start(player, enemy, world);
            inBattle = true;
            battleEnemyX = ex; battleEnemyY = ey;
            return;
        }
        if (world.IsNearNPC() || (world.GetPlayerX() == 0 && world.GetPlayerY() == 0)) {
            if (!questActive && !questCompleted) { 
                cout << "NPC: Bring me one Goblin Ear. (Quest started)" << endl; 
                questActive = true; 
                world.SpawnEnemy(); 
                world.SpawnExtraEnemy();
                cout << "Enemies spawned! Check the map." << endl;
            }
            else if (questActive && player.HasItem("Goblin Ear")) { 
                cout << "NPC: Thank you! (Quest completed)" << endl; 
                player.RemoveItemByName("Goblin Ear"); 
                player.AddGold(5); 
                // Give sword and armor as quest reward
                player.AddItem("Iron Sword");
                player.AddItem("Leather Armor");
                cout << "You received Iron Sword and Leather Armor as quest reward!" << endl;
                questActive = false; 
                questCompleted = true; 
                world.ActivateMerchantAtNPC();
                // Spawn second NPC for second quest
                world.SpawnSecondNPC();
            }
            else if (questCompleted && !secondQuestActive && !secondQuestCompleted) {
                cout << "NPC: You already helped me. Safe travels!" << endl;
            }
            else if (questCompleted && secondQuestActive && !secondQuestCompleted) {
                cout << "NPC: Still waiting for a Goblin Ear..." << endl;
            }
            else { cout << "NPC: Still waiting for a Goblin Ear..." << endl; }
        } else if (world.IsNearSecondNPC()) {
            if (!secondQuestActive && !secondQuestCompleted && questCompleted) {
                cout << "Second NPC: I need you to defeat the powerful Dragon! (Second Quest started)" << endl;
                secondQuestActive = true;
                world.SpawnDragon();
                // Create strong dragon
                enemy = Enemy(150, 25); // 150 HP, 25 damage
                enemy.SetMagical(true);
            }
            else if (secondQuestActive && !secondQuestCompleted) {
                cout << "Second NPC: Have you defeated the Dragon yet?" << endl;
            }
            else if (secondQuestCompleted) {
                cout << "Second NPC: Thank you! You have saved our village! (Game completed!)" << endl;
                gameFinished = true;
            }
        } else {
            cout << "You talk to a villager. They wish you luck on your quest." << endl;
        }
        return;
    }
    if (cmd == "trade") {
        if (inBattle || (world.HasEnemy() && world.DistToEnemy() <= 5)) { cout << "Too dangerous to trade near enemy." << endl; return; }
        if (!world.IsNearMerchant() || !world.HasMerchant()) { cout << "No merchant here." << endl; return; }
        ShowShop();
        return;
    }
    
    // Debug command to add items
    if (cmd == "add" && parts.size() >= 2) {
        std::string item;
        for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) item += ' '; item += parts[i]; }
        item = Utils::Trim(item);
        player.AddItem(item);
        return;
    }
    
    // Debug command to spawn enemies
    if (cmd == "spawn") {
        if (parts.size() >= 2) {
            std::string enemyType;
            for (size_t i = 1; i < parts.size(); ++i) { if (i > 1) enemyType += ' '; enemyType += parts[i]; }
            enemyType = Utils::Trim(enemyType);
            
            if (enemyType == "dragon" || enemyType == "Dragon") {
                world.SpawnDragon();
                enemy = Enemy(150, 25); // Dragon stats
                enemy.SetMagical(true);
                cout << "Dragon spawned!" << endl;
            } else if (enemyType == "enemy" || enemyType == "Enemy") {
                world.SpawnEnemy();
                enemy = Enemy(); // Regular enemy stats
                cout << "Regular enemy spawned!" << endl;
            } else {
                cout << "Unknown enemy type. Use 'dragon' or 'enemy'." << endl;
            }
        } else {
            cout << "Usage: spawn <enemy_type>" << endl;
            cout << "Available types: dragon, enemy" << endl;
        }
        return;
    }

    // if this is not an attacking command — burn bonus turn if exists
    if (bonusNoAttackTurns > 0) bonusNoAttackTurns = 0;
    cout << "Unknown command. Type 'help'." << endl;
}

void Game::UseSkill(const std::string& name) {
    if (!inBattle) { cout << "Skills are only available in battle." << endl; return; }
    if (bonusNoAttackTurns > 0) { cout << "Cannot attack/use skill in bonus turn." << endl; return; }
    if (name == "Power Strike") {
        enemy.TakeDamage(25);
        cout << "You used Power Strike!" << endl;
    } else {
        cout << "Unknown skill." << endl;
        return;
    }
    if (!battle.CheckWin()) { battle.EnemyTurn(); }
    if (battle.CheckWin()) {
        if (enemy.IsDead()) {
            int baseGold = 10; int bonus = (player.GetEquipped() == "Goblin Ear") ? 1 : 0; player.AddGold(baseGold + bonus);
            
            // Check if this is dragon or regular enemy
            if (world.HasDragon() && !world.IsDragonDefeated()) {
                cout << "You defeated the mighty Dragon!" << endl;
                secondQuestCompleted = true;
                world.ClearMainEnemy();
                world.ClearDragon(); // Remove dragon from map
                world.SetDragonDefeated(true);
                // Don't create new enemy object for dragon - dragon is permanently defeated
            } else {
                static bool guaranteedEarPending = true;
                if (guaranteedEarPending) { player.AddItem("Goblin Ear"); guaranteedEarPending = false; }
                else {
                    int roll = Utils::RandomInt(1, 100);
                    if (roll <= 60) player.AddItem("Goblin Ear"); else if (roll <= 85) player.AddItem("Small Potion"); else player.AddItem("Rusty Dagger");
                }
                battle.End(); inBattle = false; world.ClearMainEnemy();
                // Create new enemy object only for regular enemies
                enemy = Enemy();
            }
        }
    }
}

void Game::CastSpell(const std::string& name) {
    if (!inBattle) { cout << "Spells are only available in battle." << endl; return; }
    if (bonusNoAttackTurns > 0) { cout << "Cannot attack/cast in bonus turn." << endl; return; }
    
    int manaCost = 0;
    if (name == "Fireball") {
        manaCost = 15;
        if (player.GetMana() < manaCost) {
            cout << "Not enough mana for Fireball! Need: " << manaCost << ", have: " << player.GetMana() << endl;
            return;
        }
        enemy.TakeDamage(20);
        player.RestoreMana(-manaCost); // Consume mana
        cout << "You cast Fireball! (-" << manaCost << " mana)" << endl;
    } else if (name == "Heal") {
        manaCost = 10;
        if (player.GetMana() < manaCost) {
            cout << "Not enough mana for Heal! Need: " << manaCost << ", have: " << player.GetMana() << endl;
            return;
        }
        player.Heal(player.GetMaxHp() - player.GetHP()); // Heal to full
        player.RestoreMana(-manaCost); // Consume mana
        cout << "You cast Heal! (-" << manaCost << " mana)" << endl;
    } else if (name == "Lightning") {
        manaCost = 20;
        if (player.GetMana() < manaCost) {
            cout << "Not enough mana for Lightning! Need: " << manaCost << ", have: " << player.GetMana() << endl;
            return;
        }
        enemy.TakeDamage(25);
        player.RestoreMana(-manaCost); // Consume mana
        cout << "You cast Lightning! (-" << manaCost << " mana)" << endl;
    } else {
        cout << "Unknown spell." << endl;
        return;
    }
    
    if (!battle.CheckWin()) { battle.EnemyTurn(); }
    if (battle.CheckWin()) {
        if (enemy.IsDead()) {
            int baseGold = 10; int bonus = (player.GetEquipped() == "Goblin Ear") ? 1 : 0; player.AddGold(baseGold + bonus);
            
            // Check if this is dragon or regular enemy
            if (world.HasDragon() && !world.IsDragonDefeated()) {
                cout << "You defeated the mighty Dragon!" << endl;
                secondQuestCompleted = true;
                world.ClearMainEnemy();
                world.ClearDragon(); // Remove dragon from map
                world.SetDragonDefeated(true);
                // Don't create new enemy object for dragon - dragon is permanently defeated
            } else {
                int roll = Utils::RandomInt(1, 100);
                if (roll <= 60) player.AddItem("Goblin Ear"); else if (roll <= 85) player.AddItem("Small Potion"); else player.AddItem("Rusty Dagger");
                battle.End(); inBattle = false; world.ClearMainEnemy();
                // Create new enemy object only for regular enemies
                enemy = Enemy();
            }
        }
    }
}
