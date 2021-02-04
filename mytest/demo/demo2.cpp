#include "mytest.h"
#include <unordered_set>
/*TEST_CASE("Demo2.cpp test case 1") {
    CHECK(2 * 2 == 4), CHECK(true);
}

TEST_CASE("Demo2.cpp test case 2") {
    CHECK(true);// CHECK(2 * 2 == 5);
}

TEST_CASE("Demo2.cpp test case with multiple failures and messages") {
    CHECK_MESSAGE(2 * 2 == 4, "demo2-msg1");
    CHECK_MESSAGE(2 * 2 == 5-1, "demo2-msg2");
        CHECK_TIME("AFTER 2 CHECKS");
        int sum=0;
        for(int i=0; i<23478; ++i){
                sum+=i*(i-15)%3;
        }
        //CHECK(sum==5);
        CHECK_TIME("AFTER BIG FOR");
    CHECK(true), CHECK(2 * 2 == 4);
    //CHECK(2 * 2 == 5), CHECK(true);
}*/

TEST_CASE("CHECK ht time") {
  std::unordered_set<int> ht;
  for (int i = 0; i < 10000000; ++i) {
    ht.insert(i);
  }
  CHECK_TIME("AFTER 10000000 INSERTS");
  for (int i = 0; i < 10000000; ++i) {
    ht.erase(i);
  }
  CHECK_TIME("AFTER 10000000 ERASE");
}
