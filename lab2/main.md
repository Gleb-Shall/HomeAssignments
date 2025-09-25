# RPG Adventure Game

A console-based role-playing game built in C++ with comprehensive object-oriented design.

## Overview

This project is a text-based RPG game featuring:
- **Combat System**: Turn-based combat with weapons, armor, and magic
- **Character Progression**: Leveling system with stats and abilities
- **Inventory Management**: Equipment, potions, and item trading
- **Quest System**: NPCs with quests and rewards
- **World Exploration**: 2D grid-based world with various locations

## Architecture

The game follows object-oriented programming principles with:
- **Inheritance**: Item hierarchy (Weapon, Armor, Potion inherit from Item)
- **Composition**: Game contains Player, World, Battle systems
- **Polymorphism**: Virtual methods for different item types
- **Encapsulation**: Private data members with public interfaces

## Key Classes

### Core Game Classes
- **Game**: Main controller managing the game loop and state
- **Player**: Player character with stats, inventory, and abilities
- **Enemy**: AI-controlled opponents with various abilities
- **World**: 2D world management and entity positioning

### Item System
- **Item**: Base class for all game items
- **Weapon**: Combat weapons with damage and durability
- **Armor**: Defensive equipment with protection values
- **Potion**: Consumable items with various effects

### Game Systems
- **Battle**: Turn-based combat management
- **Inventory**: Item storage and management
- **Quest**: Quest tracking and completion
- **Shop**: Trading system for buying/selling items

## Features

- **Combat Mechanics**: Attack, defend, use items, cast spells
- **Character Stats**: HP, Mana, Level, Attack Power
- **Equipment System**: Weapons, armor, and artifacts
- **Magic System**: Spells with mana costs and cooldowns
- **NPC Interactions**: Dialog system and quest giving
- **Shop System**: Buy and sell items with gold economy
- **Logging System**: Debug and game event logging

## Getting Started

### Prerequisites
- C++ compiler (g++, clang, or MSVC)
- Make utility
- Doxygen (for documentation generation)

### Building
```bash
cd lab2/game
make
```

### Running
```bash
./game
```

### Generating Documentation
```bash
cd lab2
doxygen Doxyfile
```

## Documentation

Complete API documentation is available in the `docs/html/` directory. Open `docs/html/index.html` in a web browser to view the full documentation.

## Project Structure

```
lab2/
├── game/
│   ├── include/          # Header files (.h)
│   ├── src/              # Source files (.cpp)
│   ├── tests/            # Unit tests
│   └── Makefile          # Build configuration
├── docs/                 # Generated documentation
├── Architecture_description/  # Architecture diagrams
└── Doxyfile             # Documentation configuration
```

## Author

**Gleb Shikunov**

This project demonstrates advanced C++ programming concepts including:
- Object-oriented design patterns
- Memory management
- Template usage
- Exception handling
- Documentation generation with Doxygen
