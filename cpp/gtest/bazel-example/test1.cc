#include <gtest/gtest.h>

// Simple test example
TEST(SampleTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
