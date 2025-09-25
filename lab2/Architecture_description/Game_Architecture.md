# Game Architecture "RPG Adventure"

## Overview

This is a console RPG game written in C++ that represents a text-based adventure game with elements of combat system, inventory, quests, and trading.

## Main System Components

### 1. Game Engine
- **Game** - main class managing the game loop
- **World** - game world and map management
- **Battle** - combat system

### 2. Game Entities
- **Player** - player with characteristics, inventory, and abilities
- **Enemy** - enemies with various characteristics
- **NPC** - non-player characters for interaction

### 3. Item System
- **Item** - base class for all items
- **Weapon** - weapons with damage and durability
- **Armor** - armor with defense and durability
- **Potion** - potions with various effects

### 4. Game Systems
- **Inventory** - player inventory management
- **Quest** - quest system
- **Shop** - trading system
- **Skill** - skills and abilities system
- **Magic** - magic system (inherits from Skill)

### 5. Auxiliary Systems
- **Logger** - logging system
- **Menu** - user interface
- **Dialog** - dialog system
- **Utils** - utility functions

## Architectural Patterns

### 1. Inheritance
Used to create hierarchies of items and abilities:
- `Item` (base class)
  - `Weapon` (weapons)
  - `Armor` (armor)
  - `Potion` (potions)
- `Skill` (base class for abilities)
  - `Magic` (spells)

### 2. Composition
- `Game` contains instances of `Player`, `Enemy`, `Battle`, `World`
- `Player` contains `Inventory` and item collections
- `World` contains a two-dimensional grid of `MapTile`

### 3. Polymorphism
- `Use()` method in `Item` class is overridden in derived classes
- Virtual `Clone()` methods for creating item copies

## Game Process

### Main Loop
1. **Initialization** - creating player, world, loading data
2. **Game Loop**:
   - Processing user commands
   - Updating game state
   - Rendering interface
3. **Completion** - saving progress, exit

### Interaction Systems
- **Movement** - moving around the map
- **Combat** - turn-based combat system
- **Skills** - using special abilities
- **Spells** - applying magical abilities
- **Trading** - buying/selling items
- **Quests** - completing NPC tasks
- **Inventory** - item management


## Detailed Class Description

### Main Game Classes

#### Game
Main game controller managing the entire game process:
- **Main methods**: `Init()`, `Run()`, `Render()`, `Update()`, `Exit()`
- **State management**: tracks combat state, active quests, game completion
- **Command processing**: `HandleCommand()`, `PrintHelp()`, `ShowShop()`
- **Contains**: instances of Player, Enemy, Battle, World

#### Player
Central player entity with full set of characteristics:
- **Main characteristics**: HP, mana, level, attack, defense
- **Economy**: gold, inventory, equipped weapons and armor
- **Abilities**: skills, spells, buffs
- **Combat methods**: `Attack()`, `Defend()`, `TakeDamage()`, `Heal()`
- **Item management**: `UseItem()`, `Equip()`, `AddItem()`, `RemoveItemByName()`
- **Upgrade system**: `UpgradeWeapon()`, `UpgradeArmor()`

#### Enemy
Enemies with various characteristics and behavior:
- **Main characteristics**: HP, attack, defense
- **States**: defense, magical abilities, buffs
- **Combat methods**: `Attack()`, `Defend()`, `Think()` (AI)
- **Management**: `TakeDamage()`, `DropLoot()`, `Reset()`

#### Battle
Turn-based combat system:
- **Combat management**: `Start()`, `End()`, `IsActive()`
- **Turns**: `PlayerTurn()`, `EnemyTurn()`
- **Result checking**: `CheckWin()`
- **Participants**: references to Player, Enemy, World

#### World
Game world and map management:
- **Map**: 10x10 two-dimensional grid with tiles
- **Movement**: `MovePlayer()`, `MoveEnemyTowardPlayer()`, `MoveEnemyRandom()`
- **Object spawning**: `SpawnEnemy()`, `SpawnExtraEnemy()`, `SpawnDragon()`
- **Checks**: `IsNearEnemy()`, `IsAtNPC()`, `IsAtMerchant()`
- **NPCs and merchants**: position and activation management

### Item System

#### Item (Base Class)
Abstract base class for all items:
- **Main properties**: name, description, value
- **Virtual methods**: `Use()`, `GetName()`, `GetDescription()`, `Clone()`
- **Polymorphism**: allows unified work with different item types

#### Weapon
Weapons with damage and durability:
- **Specific properties**: damage, durability, max durability
- **Methods**: `GetDamage()`, `Upgrade()`, `Break()`, `Repair()`
- **Inheritance**: from Item with `Use()` and `Clone()` overrides

#### Armor
Armor with defense and durability:
- **Specific properties**: defense, durability, max durability
- **Methods**: `GetDefense()`, `Upgrade()`, `Break()`, `Repair()`
- **Inheritance**: from Item with `Use()` and `Clone()` overrides

#### Potion
Potions with various effects:
- **Specific properties**: effect, power, expiration
- **Methods**: `Drink()`, `GetEffect()`, `IsExpired()`
- **Inheritance**: from Item with `Use()` and `Clone()` overrides

### Ability System

#### Skill
Base class for skills and abilities:
- **Main properties**: name, description, cost, cooldown
- **Methods**: `GetCost()`, `Upgrade()`, `Cooldown()`
- **Management**: tracking availability and cooldown

#### Magic
Spells inheriting from Skill:
- **Additional properties**: mana cost, power
- **Methods**: `Cast()`, `GetManaCost()`, `Enchant()`
- **Specificity**: requires mana, can enchant items

### Interaction System

#### NPC
Non-player characters for dialogs and quests:
- **Main properties**: name, dialog, quest state
- **Methods**: `Talk()`, `GiveQuest()`, `ReceiveItem()`, `Reward()`
- **Quest management**: `HasQuest()`, `CompleteQuest()`

#### Quest
Quest and task system:
- **Main properties**: description, reward, completion state
- **Methods**: `Complete()`, `IsStarted()`, `IsCompleted()`
- **Integration**: works with Player for reward distribution

#### Shop
Trading system:
- **Item management**: `AddItem()`, `RemoveItem()`, `ListGoods()`
- **Trading**: `Buy()`, `Sell()`
- **Storage**: collection of Item pointers

### Auxiliary Systems

#### MapTile
Individual game map tiles:
- **Properties**: type, walkability, occupancy
- **Methods**: `SetType()`, `IsWalkable()`, `IsOccupied()`

