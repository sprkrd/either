#include <gtest/gtest.h>
#include <ash/either.hpp>

namespace {

using namespace ash;
using namespace std;

TEST(EitherTest, BasicMethods) {
  Either<int, string> number_or_string(42);
  EXPECT_TRUE(number_or_string.isLeft());
  EXPECT_FALSE(number_or_string.isRight());
  EXPECT_EQ(number_or_string.getLeft(), 42);
  EXPECT_THROW(number_or_string.getRight(), std::runtime_error);
}

TEST(EitherTest, MoveAssignmentTest) {
  Either<int, string> number_or_string(42);
  number_or_string = "hello world";
  EXPECT_TRUE(number_or_string.isRight());
  EXPECT_FALSE(number_or_string.isLeft());
  EXPECT_THROW(number_or_string.getLeft(), std::runtime_error);
  EXPECT_EQ(number_or_string.getRight(), "hello world");
}

TEST(EitherTest, JoinTest) {
  Either<int, string> number_or_string(42);
  string joined = number_or_string.join(
      [](int i) -> string { return to_string(i); },
      [](const string& s) -> string { return s; }
  );
  EXPECT_EQ(joined, "42");
}

}

