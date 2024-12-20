/*
   Gleb Shikunov
   st128274@student.spbu.ru
   Assignment 4
*/

#include <gtest/gtest.h>
#include <vector>
#include "Influence.h"
#include "Gun.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"

// The purpose of each test can be understood from the name of the test
TEST(TransformerTest, TransformerOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Transformer, transform\n");
}

TEST(TransformerTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Transformer, ulta\n");
}

TEST(TransformerTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer transformer;
    transformer.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Transformer, openFire\n");
}

TEST(AutobotTest, TransformOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, transform\n");
}

TEST(AutobotTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, ulta\n");
}

TEST(AutobotTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Autobot autobot;
    autobot.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Autobot, openFire\n");
}

TEST(DecepticonTest, TransformOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.transform();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, transform\n");
}

TEST(DecepticonTest, UltaOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.ulta();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, ulta\n");
}

TEST(DecepticonTest, OpenFireOutput) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Decepticon decepticon;
    decepticon.openFire();

    std::cout.rdbuf(originalBuffer);

    EXPECT_EQ(capturedOutput.str(), "Decepticon, openFire\n");
}

TEST(AutobotTest, TransformWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->transform();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, transform\n");
}

TEST(AutobotTest, UltaWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->ulta();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, ulta\n");
}

TEST(AutobotTest, OpenFireWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* autobot = new Autobot();
    autobot->openFire();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Autobot, openFire\n");
}

TEST(DecepticonTest, TransformWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->transform();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, transform\n");
}

TEST(DecepticonTest, UltaWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->ulta();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, ulta\n");
}

TEST(DecepticonTest, OpenFireWithBasePointer) {
    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    Transformer* decepticon = new Decepticon();
    decepticon->openFire();

    std::cout.rdbuf(originalBuffer);
    

    EXPECT_EQ(capturedOutput.str(), "Decepticon, openFire\n");
}


TEST(TransformerTest, VirtualMethodCallsIsCausedByBaseClass) {
    std::vector<Transformer*> transformers;

    transformers.push_back(new Autobot());
    transformers.push_back(new Autobot());
    transformers.push_back(new Autobot());

    transformers.push_back(new Decepticon());
    transformers.push_back(new Decepticon());
    transformers.push_back(new Decepticon());

    transformers.push_back(new Transformer());
    transformers.push_back(new Transformer());
    transformers.push_back(new Transformer());

    std::ostringstream capturedOutput;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(capturedOutput.rdbuf());

    for (auto& transformer : transformers) {
        transformer->transform();
        transformer->ulta();
        transformer->openFire();
    }

    std::cout.rdbuf(originalBuffer);

    EXPECT_TRUE(capturedOutput.str().find("Autobot, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, transform") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Autobot, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, ulta") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Autobot, openFire") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Decepticon, openFire") != std::string::npos);
    EXPECT_TRUE(capturedOutput.str().find("Transformer, openFire") != std::string::npos);
}
