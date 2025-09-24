#include <gtest/gtest.h>
#include "../include/MapTile.h"

class MapTileTest : public ::testing::Test {
protected:
    void SetUp() override {
        tile = new MapTile();
    }

    void TearDown() override {
        delete tile;
    }

    MapTile* tile;
};

// Test MapTile default constructor
TEST_F(MapTileTest, MapTileDefaultConstructor) {
    EXPECT_EQ(tile->GetType(), '.');
    EXPECT_FALSE(tile->IsOccupied());
}

// Test MapTile SetType method
TEST_F(MapTileTest, MapTileSetTypeMethod) {
    tile->SetType('P');
    EXPECT_EQ(tile->GetType(), 'P');
    
    tile->SetType('E');
    EXPECT_EQ(tile->GetType(), 'E');
    
    tile->SetType('D');
    EXPECT_EQ(tile->GetType(), 'D');
}

// Test MapTile SetOccupied method
TEST_F(MapTileTest, MapTileSetOccupiedMethod) {
    EXPECT_FALSE(tile->IsOccupied());
    
    tile->SetOccupied(true);
    EXPECT_TRUE(tile->IsOccupied());
    
    tile->SetOccupied(false);
    EXPECT_FALSE(tile->IsOccupied());
}

// Test MapTile with different types
TEST_F(MapTileTest, MapTileDifferentTypes) {
    MapTile playerTile;
    MapTile enemyTile;
    MapTile dragonTile;
    MapTile emptyTile;
    
    playerTile.SetType('P');
    enemyTile.SetType('E');
    dragonTile.SetType('D');
    emptyTile.SetType('.');
    
    EXPECT_EQ(playerTile.GetType(), 'P');
    EXPECT_EQ(enemyTile.GetType(), 'E');
    EXPECT_EQ(dragonTile.GetType(), 'D');
    EXPECT_EQ(emptyTile.GetType(), '.');
}

// Test MapTile occupied state with different types
TEST_F(MapTileTest, MapTileOccupiedStateWithDifferentTypes) {
    MapTile occupiedTile;
    MapTile freeTile;
    
    occupiedTile.SetType('E');
    occupiedTile.SetOccupied(true);
    
    freeTile.SetType('E');
    freeTile.SetOccupied(false);
    
    EXPECT_TRUE(occupiedTile.IsOccupied());
    EXPECT_FALSE(freeTile.IsOccupied());
}

// Test MapTile combination of type and occupied state
TEST_F(MapTileTest, MapTileTypeAndOccupiedCombination) {
    tile->SetType('P');
    tile->SetOccupied(true);
    
    EXPECT_EQ(tile->GetType(), 'P');
    EXPECT_TRUE(tile->IsOccupied());
    
    tile->SetType('.');
    tile->SetOccupied(false);
    
    EXPECT_EQ(tile->GetType(), '.');
    EXPECT_FALSE(tile->IsOccupied());
}
