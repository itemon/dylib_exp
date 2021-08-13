#include "algo.h"
#include <chrono>
#include <ctime>
#include <thread>

void findLongestNonOverlappingStr(std::string *input) {
  std::cout << "start find non overlapping sub str " << input->size() << std::endl;
  // such as "google" should be "ogle"
  // case 1 abcadef
  size_t anchor = 0;
  char current;

  size_t cursor = 0;
  size_t session_count = 0;

  size_t j = 0;

  for (size_t i = 0, len = input->size(); i < len; i++) {
    current = (*input)[i];
    if (i > 0) {
      bool duplicated = false;

      for (; j < i; j++) {
        if ((*input)[j] == current) {
          i = j + 1;
          j = i;

          std::cout << "from " << cursor << " with size " << session_count << std::endl;
          std::cout << "set cursor to " << i << std::endl;

          cursor = i;
          session_count = 1;

          duplicated = true;
          break;
        }
      }

      if (!duplicated) {
        session_count++;
      }
    } else {
      session_count++;
    }
  }

  std::cout << "from " << cursor << " with size " << session_count << std::endl;
}

#define LOG_T(T)\
  std::cout << std::asctime(std::localtime(T)) << std::endl;

void sleep_callback() {
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "thread callback time:";
  time_t thread_callback_time = time(NULL);
  LOG_T(&thread_callback_time)
}

void test_sleeping() {
  std::cout << "start build thread and block executing:";
  time_t start = time(NULL);
  LOG_T(&start)

  std::thread t(sleep_callback);
  t.join();

  time_t after_thread_startup = time(NULL);
  std::cout << "after thread startup:";
  LOG_T(&after_thread_startup)
}
