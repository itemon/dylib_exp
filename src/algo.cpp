#include "algo.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>
#include <string>
#include <future>
#include <fstream>

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
  std::cout << "thread callback time:";
  std::this_thread::sleep_for(std::chrono::seconds(5));
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

struct Vehicle {
  void operator() (double gas) {
    std::cout << "this vehicle can run with gas " << gas << std::endl;
  }
};

void test_concurrency() {
  std::cout << "CPU core count is " << std::thread::hardware_concurrency() << std::endl;
  struct Vehicle v;
  v(10.0f);
  std::cout << "the thread of this is " << std::this_thread::get_id() << std::endl;
}

std::mutex mutx;

void thread_runner(std::string name) {
  std::cout << "thread " << name << " started!" << std::endl;
  mutx.lock();
  std::cout << name << " locked" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << name << " unlocked" << std::endl;
  mutx.unlock();
}

void add_it(int a, int b, std::promise<int> pro) {
  std::cout << "about to set value of pro to " << (a + b) << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pro.set_value(a + 10);
}

typedef std::chrono::duration<int, std::ratio<15, 1>> one_quanter;

void test_mutex() {
  one_quanter three_qu(3);
  std::cout << "3 quanter is " << three_qu.count() << std::endl;
  /*
  std::thread t1(thread_runner, "master");
  std::thread t2(thread_runner, "worker");

  t1.join();
  t2.join();
  */

  std::promise<int> pro;
  std::future<int> pro_future = pro.get_future();

  std::thread pro_thread(add_it, 1, 10, std::move(pro));
  pro_thread.join();

  std::cout << "pro value is " << pro_future.get() << std::endl;

  std::future<bool> has_file = std::async(std::launch::async, [=](){
    std::ifstream corps("../if.txt", std::ios::in);
    return corps.is_open();
  });

  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "has if.txt file " << has_file.get() << std::endl;
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> span_time = end - start;
  std::cout << "call async cost " << std::chrono::duration_cast<std::chrono::nanoseconds>(span_time).count() << "ns" << std::endl;
}
