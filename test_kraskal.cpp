#include <gtest/gtest.h>

extern "C" {
    #include "kraskal.h"
}

TEST(KruskalTest, StandardGraph) {
    int V = 4;
    int E = 5;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    EXPECT_EQ(kraskal(V, E, edges), 19);
}

TEST(KruskalTest, NegativeWeights) {
    int V = 3;
    int E = 3;
    Edge edges[] = {
        {0, 1, -5}, {1, 2, -10}, {0, 2, 2}
    };
    EXPECT_EQ(kraskal(V, E, edges), -15);
}

TEST(KruskalTest, DisconnectedGraph) {
    int V = 4;
    int E = 2;
    Edge edges[] = {
        {0, 1, 5}, 
        {2, 3, 10}
    };

    EXPECT_EQ(kraskal(V, E, edges), 15);
}


TEST(KruskalTest, SingleVertex) {
    int V = 1;
    int E = 0;
    EXPECT_EQ(kraskal(V, E, nullptr), 0);
}

TEST(KruskalTest, CompleteGraph) {
    int V = 3;
    int E = 3;
    Edge edges[] = {
        {0, 1, 1}, {1, 2, 1}, {0, 2, 1}
    };

    EXPECT_EQ(kraskal(V, E, edges), 2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}