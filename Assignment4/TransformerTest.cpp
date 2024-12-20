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

// Test for the Influence class
TEST(InfluenceTest, PowerTest)
{
    Influence influence(-150);
    EXPECT_EQ(influence.get_Power(), -150);

    influence.set_Power(50);
    EXPECT_EQ(influence.get_Power(), 50);
}

// Test for the Gun class
TEST(GunTest, NameAndDamageTest)
{
    Gun gun("Rebecca", 223);
    EXPECT_EQ(gun.get_Name(), "Rebecca");
    EXPECT_EQ(gun.get_Damage(), 223);

    gun.set_Name("Poopy");
    gun.set_Damage(49);
    EXPECT_EQ(gun.get_Name(), "Poopy");
    EXPECT_EQ(gun.get_Damage(), 49);
}

// Test for the Transformers build
TEST(TransformerTest, TransformerBuild)
{
    Transformer transformer(new Gun("Rebecca", 250), 10000, "Optimus Gang", 135, 56540, 5555);

    EXPECT_EQ(transformer.get_Name(), "Optimus Gang");
    EXPECT_EQ(transformer.get_Level(), 135);
    EXPECT_EQ(transformer.get_Maxhealth(), 56540);
    EXPECT_EQ(transformer.get_TempHealth(), 5555);
    EXPECT_EQ(transformer.get_Gun()->get_Name(), "Rebecca");
    EXPECT_EQ(transformer.get_Gun()->get_Damage(), 250);
    EXPECT_EQ(transformer.get_Influence().get_Power(), 10000);
    
    transformer.set_Gun(new Gun("filter for water", 1));
    EXPECT_EQ(transformer.get_Gun()->get_Name(), "filter for water");
    EXPECT_EQ(transformer.get_Gun()->get_Damage(), 1);
    
    transformer.set_Name("MMMMonster");
    EXPECT_EQ(transformer.get_Name(), "MMMMonster");
}
// Test for the Transformers methods
TEST(TransformerTest, TransformerMethods)
{
    Transformer transformer(new Gun("Rebecca", 250), 10000, "Optimus Gang", 135, 56540, 5555);
    
    EXPECT_EQ(transformer.IsAlife(), true);
    EXPECT_EQ(transformer.fire(), true);
    EXPECT_EQ(transformer.move(), true);
}

// Test for the Autobot build and methods
TEST(AutobotTest, AutobotBuildAndMethods)
{
    Autobot autobot(new Gun("Devid", 370), 10000, "Monkey", 135, 56540, 5555, "Kung Fu Panda", 3621);
    
    EXPECT_EQ(autobot.get_Commander(), "Kung Fu Panda");
    EXPECT_EQ(autobot.get_amount_of_kindness(), 3621);
    autobot.call_Comander();
    autobot.set_Commander("zuravl");
    autobot.set_amount_of_kindness(456);
    EXPECT_EQ(autobot.get_Commander(), "zuravl");
    EXPECT_EQ(autobot.get_amount_of_kindness(), 456);
    autobot.call_Comander();
}

// Test for the Decepticon build and methods
TEST(DecepticonTest, DecepticonBuildAndMethods)
{
    Decepticon decepticon(new Gun("Lucy", 370), 10000, "Opengamer", 135, 56540, 5555, "captain Vrungel", 3621);
    
    EXPECT_EQ(decepticon.get_Commander(), "captain Vrungel");
    EXPECT_EQ(decepticon.get_amount_of_evil(), 3621);
    decepticon.call_Comander();
    decepticon.set_Commander("Helltaker");
    decepticon.set_amount_of_evil(456);
    EXPECT_EQ(decepticon.get_Commander(), "Helltaker");
    EXPECT_EQ(decepticon.get_amount_of_evil(), 456);
    decepticon.call_Comander();
}

// Test for the Minicon build and methods
TEST(MiniconTest, MiniconBuildAndMethods)
{
    Minicon minicon(new Gun("Faraday", 370), 10000, "Kingstone", 135, 56540, 5555, "Hayao Miyazaki", 3621);
    
    EXPECT_EQ(minicon.get_Master(), "Hayao Miyazaki");
    EXPECT_EQ(minicon.get_number_of_important_things_to_do(), 3621);
    minicon.call_Master();
    minicon.set_Master("Seva, moi drug");
    minicon.set_number_of_important_things_to_do(456);
    EXPECT_EQ(minicon.get_Master(), "Seva, moi drug");
    EXPECT_EQ(minicon.get_number_of_important_things_to_do(), 456);
    minicon.call_Master();
}
