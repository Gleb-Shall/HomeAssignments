#include <gtest/gtest.h>
#include "../include/Player.h"

class SeparateSlotsTest : public ::testing::Test {
protected:
    Player* player;

    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }
};

// Test initial empty slots
TEST_F(SeparateSlotsTest, InitialEmptySlots) {
    EXPECT_EQ(player->GetEquipped(), "") << "Weapon slot should be empty initially";
    EXPECT_EQ(player->GetEquippedArmor(), "") << "Armor slot should be empty initially";
    EXPECT_EQ(player->GetEquippedArtifact(), "") << "Artifact slot should be empty initially";
}

// Test weapon slot
TEST_F(SeparateSlotsTest, WeaponSlot) {
    player->AddItem("Iron Sword");
    player->Equip("Iron Sword");
    
    EXPECT_EQ(player->GetEquipped(), "Iron Sword") << "Weapon should be equipped in weapon slot";
    EXPECT_EQ(player->GetEquippedArmor(), "") << "Armor slot should remain empty";
    EXPECT_EQ(player->GetEquippedArtifact(), "") << "Artifact slot should remain empty";
}

// Test armor slot
TEST_F(SeparateSlotsTest, ArmorSlot) {
    player->AddItem("Leather Armor");
    player->EquipArmor("Leather Armor");
    
    EXPECT_EQ(player->GetEquipped(), "") << "Weapon slot should remain empty";
    EXPECT_EQ(player->GetEquippedArmor(), "Leather Armor") << "Armor should be equipped in armor slot";
    EXPECT_EQ(player->GetEquippedArtifact(), "") << "Artifact slot should remain empty";
}

// Test artifact slot
TEST_F(SeparateSlotsTest, ArtifactSlot) {
    player->AddItem("Goblin Ear");
    player->EquipArtifact("Goblin Ear");
    
    EXPECT_EQ(player->GetEquipped(), "") << "Weapon slot should remain empty";
    EXPECT_EQ(player->GetEquippedArmor(), "") << "Armor slot should remain empty";
    EXPECT_EQ(player->GetEquippedArtifact(), "Goblin Ear") << "Artifact should be equipped in artifact slot";
}

// Test all slots can be filled simultaneously
TEST_F(SeparateSlotsTest, AllSlotsSimultaneously) {
    // Add all items
    player->AddItem("Iron Sword");
    player->AddItem("Leather Armor");
    player->AddItem("Goblin Ear");
    
    // Equip all items
    player->Equip("Iron Sword");
    player->EquipArmor("Leather Armor");
    player->EquipArtifact("Goblin Ear");
    
    EXPECT_EQ(player->GetEquipped(), "Iron Sword") << "Weapon should be equipped";
    EXPECT_EQ(player->GetEquippedArmor(), "Leather Armor") << "Armor should be equipped";
    EXPECT_EQ(player->GetEquippedArtifact(), "Goblin Ear") << "Artifact should be equipped";
}

// Test switching items in same slot
TEST_F(SeparateSlotsTest, SwitchingItemsInSameSlot) {
    // Add two weapons
    player->AddItem("Iron Sword");
    player->AddItem("Rusty Dagger");
    
    // Equip first weapon
    player->Equip("Iron Sword");
    EXPECT_EQ(player->GetEquipped(), "Iron Sword") << "First weapon should be equipped";
    
    // Switch to second weapon
    player->Equip("Rusty Dagger");
    EXPECT_EQ(player->GetEquipped(), "Rusty Dagger") << "Second weapon should replace first";
}

// Test equipping non-existent items
TEST_F(SeparateSlotsTest, EquippingNonExistentItems) {
    // Try to equip non-existent items
    player->Equip("Non-existent Weapon");
    player->EquipArmor("Non-existent Armor");
    player->EquipArtifact("Non-existent Artifact");
    
    EXPECT_EQ(player->GetEquipped(), "") << "Weapon slot should remain empty";
    EXPECT_EQ(player->GetEquippedArmor(), "") << "Armor slot should remain empty";
    EXPECT_EQ(player->GetEquippedArtifact(), "") << "Artifact slot should remain empty";
}
