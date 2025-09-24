#pragma once
#include <string>
#include <vector>
class Item; // forward declare
class Enemy; // forward declare

class Player {
public:
    Player();
    void Attack(Enemy& enemy);
    void Defend();
    void UseItem(Item& item);
    void Move(int dx, int dy);
    void LevelUp();

    void TakeDamage(int dmg);
    void Heal(int amount);
    int GetHP() const;
    bool IsDefending() const;
    // economy & inventory
    void AddGold(int amount);
    int GetGold() const;
    void AddItem(const std::string& name);
    const std::vector<std::string>& GetInventory() const;
    bool Equip(const std::string& name);
    std::string GetEquipped() const;
    bool HasItem(const std::string& name) const;
    bool RemoveItemByName(const std::string& name);
    int GetLevel() const { return level; }
    int GetMana() const { return mana; }
    int GetMaxHp() const { return maxHp; }
    int GetMaxMana() const { return maxMana; }
    void RestoreMana(int amount);
    void AddBuff(const std::string& buffName, int power, int duration);
    void RemoveBuff(const std::string& buffName);
    bool HasBuff(const std::string& buffName) const;
    int GetBuffPower(const std::string& buffName) const;
    
    // Upgrade methods
    void UpgradeWeapon();
    void UpgradeArmor();
    int GetWeaponUpgrades() const { return weaponUpgrades; }
    int GetArmorUpgrades() const { return armorUpgrades; }
    
    // Armor methods
    void EquipArmor(const std::string& name);
    std::string GetEquippedArmor() const { return equippedArmor; }
    int GetArmorDefense() const;
    
    // Artifact methods
    void EquipArtifact(const std::string& name);
    std::string GetEquippedArtifact() const { return equippedArtifact; }
private:
    int hp;
    int maxHp;
    int mana;
    int maxMana;
    int level;
    int attackPower;
    bool defending;
    int gold;
    std::vector<std::string> inventory;
    std::string equipped; // weapon slot
    std::string equippedArmor; // armor slot
    std::string equippedArtifact; // artifact slot
    
    // Upgrade tracking
    int weaponUpgrades;
    int armorUpgrades;
    
    struct Buff {
        std::string name;
        int power;
        int duration;
    };
    std::vector<Buff> buffs;
};
