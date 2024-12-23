/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 6
*/


#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Transformer.h"

// Tests for Class1
TEST(TransformerTest, Class1FooTrue) 
{
    Class1 cl1;
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class1, int> transformer(5, vec, cl1);
    EXPECT_EQ(transformer.foo(), true);
}


TEST(TransformerTest, Class1FooFalse) 
{
    Class1 cl1;
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class1, int> transformer(-5, vec, cl1);
    EXPECT_EQ(transformer.foo(), false);
}

// Tests for Class2
TEST(TransformerTest, Class2FooTrue) 
{
    Class2 cl2;
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class2, int> transformer(1, vec, cl2);
    EXPECT_EQ(transformer.foo(), true);
}

TEST(TransformerTest, Class2FooFalse) 
{
    Class2 cl2;
    std::vector<float> vec;
    Transformer<Class2, int> transformer(-5, vec, cl2);
    EXPECT_EQ(transformer.foo(), false);
}

// Tests for Class3
TEST(TransformerTest, Class3FooTrue) 
{
    Class3 cl3;
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class3, int> transformer(-3, vec, cl3);
    EXPECT_EQ(transformer.foo(), true);
}

TEST(TransformerTest, Class3FooFalse) 
{
    Class3 cl3;
    std::vector<float> vec = {1.0f, 2.0f, 3.0f};
    Transformer<Class3, int> transformer(3, vec, cl3);
    EXPECT_EQ(transformer.foo(), false);
}

// Tests for specializations
TEST(TransformerTest, IntSpecializationAlwaysTrue) 
{
    Class1 cl1;
    Transformer<int, Class1> transformer(0, {}, cl1);
    EXPECT_TRUE(transformer.foo());
}

TEST(TransformerTest, DoubleSpecializationAlwaysFalse) 
{
    Class1 cl1;
    Transformer<double, Class1> transformer(0, {}, cl1);
    EXPECT_FALSE(transformer.foo());
}
