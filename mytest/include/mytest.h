#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#ifndef MYTEST_H_
#define MYTEST_H_

namespace mytest {
/*void add(){
        std::cout<<2;
};
void erase(){
        std::cout<<1;
};*/
void add();
void erase();
void start_time();
int all_time_work();
//HANDLE get_h(); // = GetStdHandle(STD_OUTPUT_HANDLE);
void CHECK_F(bool ex, int line, const std::string &file,
             const std::string &my_expression);
void CHECK_MESSAGE_F(bool ex, int line, const std::string &sfile,
                     const std::string &my_expression,
                     const std::string &my_message);
void CHECK_T(const std::string &mark);
int get_string();
bool nowtest();
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define CHECK_TIME(x) mytest::CHECK_T(x)

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define CHECK(x) mytest::CHECK_F(x, __LINE__, std::string(__FILE__), #x)

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define CHECK_MESSAGE(x, mes)                                                  \
  ;                                                                            \
  mytest::CHECK_MESSAGE_F(x, __LINE__, std::string(__FILE__), #x, mes);

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE(class_name, name)                            \
  static void class_name(); /*не выползет*/                          \
  namespace {               /*и тут не выползет*/                \
  struct Magic##class_name {                                                   \
    Magic##class_name() {                                                      \
     /* SetConsoleTextAttribute(mytest::get_h(), (WORD)((0 << 4) | 15)); */        \
      std::cerr << "\x1b[0mRunning " << #name << "...\n\x1b[0m";                             \
      mytest::start_time();                                                    \
      mytest::add();                                                           \
      class_name();                                                            \
      std::string s = "\x1b[31m";                                                               \
      if (mytest::nowtest())                                                   \
        s = "\x1b[32m";                                                                 \
      /*SetConsoleTextAttribute(mytest::get_h(), (WORD)((0 << 4) | s));*/          \
      std::cerr << s << #name << " end at ";                                        \
      /*SetConsoleTextAttribute(mytest::get_h(), (WORD)((0 << 4) | 14));*/         \
      std::cerr << "\x1b[33m" << (float(mytest::all_time_work())) / CLOCKS_PER_SEC << " s\x1b[0m\n\n";                       \
    }                                                                          \
  } magia##class_name;                                                         \
  } /*anonymus namespace end*/                                                 \
  static void class_name()

// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE2(line, name)                                 \
  MYTEST_INTERNAL_TEST_CASE(mytest_test_class_##line, name)
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define MYTEST_INTERNAL_TEST_CASE1(line, name)                                 \
  MYTEST_INTERNAL_TEST_CASE2(line, name)
// NOLINTNEXTLINE: cppcoreguidelines-macro-usage
#define TEST_CASE(name) MYTEST_INTERNAL_TEST_CASE1(__LINE__, name)

} // namespace mytest

#endif // MYTEST_H_
