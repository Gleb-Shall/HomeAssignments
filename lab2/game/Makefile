CXX := g++
CXXFLAGS := -std=c++17 -O1 -g -Wall -Wextra
INCLUDES := -Iinclude
SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/game

SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/Enemy.cpp $(SRC_DIR)/Battle.cpp \
        $(SRC_DIR)/Item.cpp $(SRC_DIR)/Weapon.cpp $(SRC_DIR)/Armor.cpp $(SRC_DIR)/Potion.cpp \
        $(SRC_DIR)/Inventory.cpp $(SRC_DIR)/NPC.cpp $(SRC_DIR)/Quest.cpp $(SRC_DIR)/Dialog.cpp \
        $(SRC_DIR)/Skill.cpp $(SRC_DIR)/Magic.cpp $(SRC_DIR)/Shop.cpp $(SRC_DIR)/Logger.cpp $(SRC_DIR)/Menu.cpp \
        $(SRC_DIR)/World.cpp $(SRC_DIR)/Utils.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJS)
	@echo "Cleaning up object files..."
	@rm -f $(OBJS)
	@echo "Build complete! Binary: $(TARGET)"

# Build without cleaning object files (for debugging)
build: $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)
	@echo "Build complete! Binary: $(TARGET) (object files preserved)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

.PHONY: all build clean
