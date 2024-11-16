#include <gtest/gtest.h>
#include "lib.h"

TEST(TestLib, FastInverseSquareRoot) {
  EXPECT_NEAR(0.7071, Q_rsqrt(2), 1e-4);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
