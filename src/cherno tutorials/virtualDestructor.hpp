//虚析构函数非常重要，尤其是内存泄漏问题
#include <iostream>

class Base {
 public:
  Base();
  ~Base();

 private: 
};

Base::Base() { std::cout << "Base Constructor!\n"; }

Base::~Base() { std::cout << "Base Destructor!\n"; }

class Derived:public Base {
 public:
  Derived();
  ~Derived();

 private:
};

Derived::Derived() { std::cout << "Base Constructor!\n"; }

Derived::~Derived() { std::cout << "Base Destructor!\n"; }

void OutputDivider() { std::wcout << "---------------\n"; }

// show the memory leak problem!
void MemoryLeak() {
  Base* base = new Base;
  delete base;
  OutputDivider();
  Derived* derived = new Derived;
  delete derived;
  OutputDivider();
  // cause memory leak ! Doesn't call derived class destructor!
  // if derived class had newed a array,it must cause memory leak
  Base* child = new Derived;
  // in order to solve the question you can make the base destructor virtual,causing it to v-table

  delete child;
}