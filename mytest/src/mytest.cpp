#include "mytest.h"
#include <stdio.h>
namespace mytest {
// namespace {
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int good_test = 0; //счётчик хороших тестов
int all_test = 0;  //счётчик плохих тестов
bool now_test = false; //все ли CHECK в нынешнем тесты верны?
int time_start;        //время начала работы теста
void add() { //срабатывает при открытии нового теста
  if (now_test) {
    ++good_test; //все чеки в предыдущем тесте зашли
  }
  now_test = true; //ничего тоже верно
  all_test++;
}
void erase() { //плохой CHECK
  now_test = false;
}
bool nowtest() { return now_test; }
void start_time() { time_start = clock(); }

int all_time_work() { return clock() - time_start; }

//HANDLE get_h() { return hConsole; }

void CHECK_F(bool ex, int line, const std::string &file,
             const std::string &my_expression) {
  if (!ex) {
//    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
    std::cerr << "\x1b[31m    CHECK(" << my_expression << ") at "
              << file /*std::string(__FILE__)*/ << ":" << line << " failed!\n\x1b[0m";
    erase();
  }
}

void CHECK_MESSAGE_F(bool ex, int line, const std::string &file,
                     const std::string &my_expression,
                     const std::string &my_message) {
  if (!ex) {
  //  SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
    std::cerr << "\x1b[31m    CHECK(" << my_expression << ") at "
              << file /*std::string(__FILE__)*/ << ":" << line << " failed!\n";
   // SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
    std::cerr << "\x1b[33m        message: " << my_message << "\n\x1b[0m";
    erase();
  }
}

void CHECK_T(const std::string &mark) {
 // SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
  std::cerr << "\x1b[33m    TIME: \x1b[0m";
  //SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
  std::cerr << (float(clock() - time_start))/ CLOCKS_PER_SEC << " s from the start of this test;";
  //SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
  std::cerr << "\x1b[33m MARK: \x1b[0m";
  //SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
  std::cerr << mark << "\n";
}
// File-local declarations and definitions.
//}  // namespace
int get_string() {
  if (now_test) {
    ++good_test; //последний мы так и не проверили до этого
  }
  int s;
  if (good_test == all_test) {
    s = 32;
  } else {
    s = 31;
  }
//  SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | s));
  std::cerr << "\x1b["<<s<<"m===== Tests passed: " << good_test << "/" << all_test
            << " =====\n\x1b[0m";
 // SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
  if (good_test == all_test) {
    return 0;
  } else {
    return 1;
  }
}
// Externally visible declarations and definitions.
} // namespace mytest
