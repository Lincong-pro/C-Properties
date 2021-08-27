#pragma 
#include <thread>
#include <iostream>
#include <memory>
using namespace std::literals::chrono_literals;
//使用仿函数的方式作为多线程的可调用对象
class  TA {
 public:
  TA();
  //对于这种引用类型还是会复制一份到内存中，即便外部的局部变量被销毁了也不会影响这个副本
  TA(int &i);
  TA(TA &a);
  ~ TA();
  //仿函数
  void operator()() {
    std::this_thread::sleep_for(1s);
    std::cout << "m_i is " << m_i << "\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Over how the m_i is still " << m_i << "\n";
  }
 private:
  int m_i;
};


void testThreadRef();