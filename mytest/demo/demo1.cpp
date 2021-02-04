#include "mytest.h"

TEST_CASE("Demo1.cpp test case 1") { CHECK(2 * 2 == 4); }

TEST_CASE("Demo1.cpp test case 2") {
  CHECK(2 * 2 == 5 - 1);
  for (int i = 0; i < 1000; ++i) {
    CHECK(i * i % 1 == 0);
  }
}
