#include <gtest/gtest.h>
#include "../include/Menu.h"

class MenuTest : public ::testing::Test {
protected:
    void SetUp() override {
        menu = new Menu();
    }

    void TearDown() override {
        delete menu;
    }

    Menu* menu;
};

// Test Menu ShowMain method
TEST_F(MenuTest, MenuShowMainMethod) {
    // ShowMain method should not crash
    menu->ShowMain();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Menu ShowInventory method
TEST_F(MenuTest, MenuShowInventoryMethod) {
    // ShowInventory method should not crash
    menu->ShowInventory();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Menu ShowShopMenu method
TEST_F(MenuTest, MenuShowShopMenuMethod) {
    // ShowShopMenu method should not crash
    menu->ShowShopMenu();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Menu ExitMenu method
TEST_F(MenuTest, MenuExitMenuMethod) {
    // ExitMenu method should not crash
    menu->ExitMenu();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Menu ShowBattleMenu method
TEST_F(MenuTest, MenuShowBattleMenuMethod) {
    // ShowBattleMenu method should not crash
    menu->ShowBattleMenu();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Menu HandleInput method
TEST_F(MenuTest, MenuHandleInputMethod) {
    // HandleInput method should not crash
    menu->HandleInput();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}
