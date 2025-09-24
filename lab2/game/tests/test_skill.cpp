#include <gtest/gtest.h>
#include "../include/Skill.h"
#include "../include/Player.h"
#include "../include/Enemy.h"

class SkillTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = new Player();
        enemy = new Enemy();
        skill = new Skill("Power Strike", "A powerful attack", 25);
    }

    void TearDown() override {
        delete player;
        delete enemy;
        delete skill;
    }

    Player* player;
    Enemy* enemy;
    Skill* skill;
};

// Test Skill constructor
TEST_F(SkillTest, SkillConstructor) {
    EXPECT_EQ(skill->GetName(), "Power Strike");
    EXPECT_EQ(skill->GetDescription(), "A powerful attack");
    EXPECT_EQ(skill->GetCost(), 25);
}

// Test Skill GetCost method
TEST_F(SkillTest, SkillGetCostMethod) {
    EXPECT_EQ(skill->GetCost(), 25);
}

// Test Skill with different cost values
TEST_F(SkillTest, SkillDifferentCostValues) {
    Skill weakSkill("Weak Attack", "A weak attack", 5);
    Skill strongSkill("Strong Attack", "A strong attack", 50);
    
    EXPECT_EQ(weakSkill.GetCost(), 5);
    EXPECT_EQ(strongSkill.GetCost(), 50);
}

// Test Skill cost getter
TEST_F(SkillTest, SkillCostProperties) {
    EXPECT_EQ(skill->GetCost(), 25);
    
    // Note: SetDamage() method doesn't exist in Skill class
    // We can only test GetCost()
}

// Test Skill Upgrade method
TEST_F(SkillTest, SkillUpgradeMethod) {
    int initialCost = skill->GetCost();
    skill->Upgrade();
    EXPECT_LT(skill->GetCost(), initialCost);
}
