/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/

#include <gtest/gtest.h>
#include "Influence.h"
#include "Gun.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Minicon.h"
#include "Decepticon.h"

// Test for the Transformers output and constructor overloading
TEST(TransformerTest, TransformerOutput)
{
    Transformer transformer1(new Gun("Rebecca", 250), 10000, "Optimus Gang", 135, 56540, 5555);
    Transformer transformer2;
    std::cout << transformer1 << transformer2;
    
    std::stringstream ss1;
    ss1 << transformer1;
    std::stringstream ss2;
    ss2 << transformer2;

    std::string expected_output1 = "Transformer Name: Optimus Gang,\nTransformer Level: 135,\nTransformer MaxHealth: 56540,\nTransformer TempHealth: 5555,\nTransformer Gun: Gun name: Rebecca, Gun Damage: 250,\ntransformer Influence: Influence.power: 10000,\n\n";
    EXPECT_EQ(ss1.str(), expected_output1);
    std::string expected_output2 = "Transformer Name: Default name,\nTransformer Level: 0,\nTransformer MaxHealth: 0,\nTransformer TempHealth: 0,\nTransformer Gun: Gun name: Defaut name, Gun Damage: 0,\ntransformer Influence: Influence.power: 0,\n\n";
    EXPECT_EQ(ss2.str(), expected_output2);
}

// Test for the Transformer compare
TEST(TransformTest, TransformerCompare)
{
    Transformer transformer1 (new Gun("Rebecca", 250), 10000, "Optimus Gang", 135, 56540, 5555);
    Transformer transformer2;
    EXPECT_EQ(transformer1 > transformer2, true);
}

// Test for the Autobot output and constructor overloading
TEST(AutobotTest, AutobotOutput)
{
    Autobot autobot1(new Gun("Devid", 370), 10000, "Monkey", 135, 56540, 5555, "Kung Fu Panda", 3621);
    Autobot autobot2;
    std::cout << autobot1 << autobot2;
    std::stringstream ss;
    ss << autobot1;
    std::string expected_output = "Autobot Commander: Kung Fu Panda,\nAutobot amount_of_kindness: 3621,\nAutobot Name: Monkey,\nAutobot Level: 135,\nAutobot MaxHealth: 56540,\nAutobot TempHealth: 5555,\nAutobot Gun: Gun name: Devid, Gun Damage: 370,\nAutobot Influence: Influence.power: 10000,\n\n";
    EXPECT_EQ(ss.str(), expected_output);
}

// Test for the Decepticon output and constructor overloading
TEST(DecepticonTest, DecepticonOutput)
{
    Decepticon decepticon1(new Gun("Lucy", 370), 10000, "Opengamer", 135, 56540, 5555, "captain Vrungel", 3621);
    Decepticon decepticon2;
    std::cout << decepticon1 << decepticon2;
    std::stringstream ss;
    ss << decepticon1;
    std::string expected_output = "Decepticon Commander: captain Vrungel,\nDecepticon amount_of_evil: 3621,\nDecepticon Name: Opengamer,\nDecepticon Level: 135,\nDecepticon MaxHealth: 56540,\nDecepticon TempHealth: 5555,\nDecepticon Gun: Gun name: Lucy, Gun Damage: 370,\nDecepticon Influence: Influence.power: 10000,\n\n";
    EXPECT_EQ(ss.str(), expected_output);
}

// Test for the Minicon output and constructor overloading
TEST(MiniconTest, MiniconOutput)
{
    Minicon minicon1(new Gun("Faraday", 370), 10000, "Kingstone", 135, 56540, 5555, "Hayao Miyazaki", 3621);
    Minicon minicon2;
    std::cout << minicon1 << minicon2;
    std::stringstream ss;
    ss << minicon1;
    std::string expected_output = "Minicon Master: Hayao Miyazaki,\nMinicon Number_of_important_things_to_do: 3621,\nMinicon Name: Kingstone,\nMinicon Level: 135,\nMinicon MaxHealth: 56540,\nMinicon TempHealth: 5555,\nMinicon Gun: Gun name: Faraday, Gun Damage: 370,\nMinicon Influence: Influence.power: 10000,\n\n";
    EXPECT_EQ(ss.str(), expected_output);
}
