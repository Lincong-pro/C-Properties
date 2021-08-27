#include "functor.h"

TA::TA() { std::cout << "constructor\n"; }

TA::TA(int& i) { std::cout << "param constructor\n"; }

TA::TA(TA& a) { std::cout << "copy constructor\n"; }

TA::~TA() { std::cout << "destructor\n"; }

void testThreadRef() {
  std::unique_ptr<std::thread> ptr=nullptr;
  {
	  //block
	int b = 1;
	TA a(b);
	ptr = std::make_unique<std::thread>(a);  //传入可调对象（仿函数）
  }
  std::cout << "ref obj has been destroyed!\n";
  ptr->join();
}