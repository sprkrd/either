#include <gtest/gtest.h>
#include <ash/either.hpp>

namespace {

TEST(DummyTest, Dummy1) {
  EXPECT_EQ(0, 1-1);
}

TEST(DummyTest, Dummy2) {
  EXPECT_FALSE(true) << "This test fails deliberatively";
}

TEST(DummyTest, Dummy3) {
  EXPECT_TRUE(true);
}

}

