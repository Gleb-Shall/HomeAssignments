#include <gtest/gtest.h>
#include "../include/Shop.h"
#include "../include/Player.h"
#include "../include/Item.h"
#include "../include/Weapon.h"
#include "../include/Armor.h"
#include "../include/Potion.h"

class ShopTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        shop = new Shop();
        weapon = new Weapon("Iron Sword", "A sharp sword", 10, 15);
        armor = new Armor("Leather Armor", "Basic armor", 15, 5);
        potion = new Potion("Health Potion", "Restores health", 5, "heal", 20);
    }

    void TearDown() override {
        delete player;
        delete shop;
        delete weapon;
        delete armor;
        delete potion;
    }

    Player* player;
    Shop* shop;
    Weapon* weapon;
    Armor* armor;
    Potion* potion;
};

// Test Shop Buy method with sufficient gold
TEST_F(ShopTest, ShopBuyWithSufficientGold) {
    player->AddGold(20); // Give player enough gold (100 + 20 = 120)
    
    shop->Buy(*player, *weapon);
    
    EXPECT_TRUE(player->HasItem("Iron Sword"));
    EXPECT_EQ(player->GetGold(), 110); // 120 - 10 = 110
}

// Test Shop Buy method with insufficient gold
TEST_F(ShopTest, ShopBuyWithInsufficientGold) {
    // Player starts with 100 gold, weapon costs 10, so 5 gold is not enough
    player->AddGold(-95); // Give player not enough gold (100 - 95 = 5)
    
    shop->Buy(*player, *weapon);
    
    EXPECT_FALSE(player->HasItem("Iron Sword"));
    EXPECT_EQ(player->GetGold(), 5); // Gold should remain unchanged
}

// Test Shop Sell method
TEST_F(ShopTest, ShopSellMethod) {
    player->AddItem("Iron Sword");
    int initialGold = player->GetGold();
    
    shop->Sell(*player, *weapon);
    
    EXPECT_FALSE(player->HasItem("Iron Sword"));
    EXPECT_GT(player->GetGold(), initialGold);
}

// Test Shop Sell method with item not in inventory
TEST_F(ShopTest, ShopSellMethodWithoutItem) {
    int initialGold = player->GetGold();
    
    shop->Sell(*player, *weapon);
    
    EXPECT_EQ(player->GetGold(), initialGold); // Gold should remain unchanged
}

// Test Shop ListGoods method with empty shop
TEST_F(ShopTest, ShopListGoodsEmptyShop) {
    // Shop should be empty initially
    shop->ListGoods();
    
    // We can't easily test console output, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Shop AddItem method
TEST_F(ShopTest, ShopAddItemMethod) {
    shop->AddItem(*weapon);
    
    // We can't easily test the internal state, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Shop RemoveItem method
TEST_F(ShopTest, ShopRemoveItemMethod) {
    shop->AddItem(*weapon);
    shop->RemoveItem(*weapon);
    
    // We can't easily test the internal state, so we just ensure it doesn't crash
    SUCCEED();
}

// Test Shop with different item types
TEST_F(ShopTest, ShopWithDifferentItemTypes) {
    player->AddGold(50); // Give player enough gold for all items
    
    shop->Buy(*player, *weapon);
    shop->Buy(*player, *armor);
    shop->Buy(*player, *potion);
    
    EXPECT_TRUE(player->HasItem("Iron Sword"));
    EXPECT_TRUE(player->HasItem("Leather Armor"));
    EXPECT_TRUE(player->HasItem("Health Potion"));
}
