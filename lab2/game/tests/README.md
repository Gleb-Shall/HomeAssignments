# Unit Tests for Game Damage System

This directory contains unit tests for the game's damage system using Google Test framework.

## Test Coverage

The tests verify the following functionality:

### Basic Damage Tests
- **BasicAttackDamage**: Verifies that basic attack deals 15 damage
- **EnemyTakesCorrectDamage**: Confirms enemy HP decreases correctly after attack

### Weapon Damage Tests
- **IronSwordDamage**: Tests that Iron Sword adds +10 damage bonus (total 25 damage)
- **RustyDaggerDamage**: Tests that Rusty Dagger adds +2 damage bonus (total 17 damage)
- **WeaponEquipping**: Verifies weapon equipping functionality
- **UnequippedWeaponNoBonus**: Confirms unequipped weapons don't affect damage

### Advanced Damage Tests
- **MultipleAttacksWithDifferentWeapons**: Tests switching between weapons mid-combat
- **IronSwordAgainstMultipleEnemies**: Verifies weapon bonus applies to multiple enemies
- **LevelUpIncreasesBaseDamage**: Confirms level up increases base attack power
- **WeaponBonusCalculation**: Verifies exact bonus calculation (+10 for Iron Sword)

## Running Tests

### Prerequisites
- Google Test framework installed (via Homebrew: `brew install googletest`)
- C++17 compatible compiler (clang++)

### Build and Run
```bash
cd tests
make clean
make
./test_damage
```

### Expected Output
All 10 tests should pass, showing:
```
[==========] Running 10 tests from 1 test suite.
[----------] 10 tests from DamageTest
[ RUN      ] DamageTest.BasicAttackDamage
[       OK ] DamageTest.BasicAttackDamage (0 ms)
...
[==========] 10 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 10 tests.
```

## Test Results Summary

✅ **All tests pass** - The damage system is working correctly:

1. **Base damage**: 15 points (Player level 1)
2. **Iron Sword bonus**: +10 damage (total 25)
3. **Rusty Dagger bonus**: +2 damage (total 17)
4. **Level up bonus**: +2 base damage per level
5. **Weapon equipping**: Works correctly
6. **Multiple enemies**: Weapon bonus applies to all targets

## Test Structure

Each test follows the pattern:
1. **SetUp**: Create fresh Player and Enemy objects
2. **Action**: Perform the test action (equip weapon, attack, etc.)
3. **Assert**: Verify expected damage values
4. **TearDown**: Clean up objects

The tests are isolated and don't affect each other, ensuring reliable results.
