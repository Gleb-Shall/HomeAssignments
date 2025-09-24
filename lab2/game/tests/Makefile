# Makefile for running tests
CXX := g++
CXXFLAGS := -std=c++17 -O1 -g -Wall -Wextra
INCLUDES := -I../include

# Google Test flags (cross-platform)
GTEST_INCLUDE := $(if $(GTEST_INCLUDE_PATH),-I$(GTEST_INCLUDE_PATH),)
GTEST_LIBS := $(if $(GTEST_LIB_PATH),-L$(GTEST_LIB_PATH),) -lgtest -lgtest_main -pthread

# Single test executable
TEST_TARGET := all_tests

# Source files
GAME_SOURCES := ../src/Player.cpp ../src/Enemy.cpp ../src/Battle.cpp ../src/Item.cpp ../src/Weapon.cpp \
                ../src/Armor.cpp ../src/Potion.cpp ../src/Inventory.cpp ../src/NPC.cpp \
                ../src/Quest.cpp ../src/Dialog.cpp ../src/Skill.cpp ../src/Magic.cpp \
                ../src/Shop.cpp ../src/Logger.cpp ../src/Menu.cpp ../src/World.cpp \
                ../src/Utils.cpp

# Object files for all tests
TEST_OBJS := test_damage.o test_enemy_death.o test_battle_after_death.o test_skills_spells.o test_upgrade_system.o test_armor_defense.o test_starting_gold.o test_heal_spell.o test_separate_slots.o test_dragon_defeat.o test_item.o test_weapon.o test_armor_class.o test_potion_class.o test_enemy_class.o test_battle_class.o test_world_class.o test_utils.o test_shop.o test_npc.o test_quest.o test_skill.o test_magic.o test_maptile.o test_inventory.o test_logger.o test_menu.o test_dialog.o $(GAME_SOURCES:.cpp=.o)

all: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -o $@ $^ $(GTEST_LIBS)
	@echo "Cleaning up object files..."
	@rm -f test_damage.o test_enemy_death.o test_battle_after_death.o test_skills_spells.o test_upgrade_system.o test_armor_defense.o test_starting_gold.o test_heal_spell.o test_separate_slots.o test_dragon_defeat.o test_item.o test_weapon.o test_armor_class.o test_potion_class.o test_enemy_class.o test_battle_class.o test_world_class.o test_utils.o test_shop.o test_npc.o test_quest.o test_skill.o test_magic.o test_maptile.o test_inventory.o test_logger.o test_menu.o test_dialog.o ../src/*.o
	@echo "Test executable built: $(TEST_TARGET)"

test_damage.o: test_damage.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_enemy_death.o: test_enemy_death.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_battle_after_death.o: test_battle_after_death.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_skills_spells.o: test_skills_spells.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_upgrade_system.o: test_upgrade_system.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_armor_defense.o: test_armor_defense.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_starting_gold.o: test_starting_gold.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_heal_spell.o: test_heal_spell.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_separate_slots.o: test_separate_slots.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_dragon_defeat.o: test_dragon_defeat.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_item.o: test_item.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_weapon.o: test_weapon.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_armor_class.o: test_armor_class.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_potion_class.o: test_potion_class.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_enemy_class.o: test_enemy_class.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_battle_class.o: test_battle_class.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_world_class.o: test_world_class.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_utils.o: test_utils.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_shop.o: test_shop.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_npc.o: test_npc.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_quest.o: test_quest.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_skill.o: test_skill.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_magic.o: test_magic.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_maptile.o: test_maptile.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_inventory.o: test_inventory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_logger.o: test_logger.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_menu.o: test_menu.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

test_dialog.o: test_dialog.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INCLUDE) -c $< -o $@

../src/%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TEST_TARGET) test_damage.o test_enemy_death.o test_battle_after_death.o test_skills_spells.o test_upgrade_system.o test_armor_defense.o test_starting_gold.o test_heal_spell.o test_separate_slots.o test_dragon_defeat.o test_item.o test_weapon.o test_armor_class.o test_potion_class.o test_enemy_class.o test_battle_class.o test_world_class.o test_utils.o test_shop.o test_npc.o test_quest.o test_skill.o test_magic.o test_maptile.o test_inventory.o test_logger.o test_menu.o test_dialog.o ../src/*.o

.PHONY: all clean
