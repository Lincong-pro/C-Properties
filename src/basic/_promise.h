#pragma 
//系统库自己定义的头文件是有保护机制的
//即便出现重复引入pragma指令还是可以保证其只被引入一次，因为其将函数体和声明完全进行分离
//如果非要在hpp里面写函数、类、结构体的声明，最后的需要自己很好的掌握调用的传递以便寻找错误
#include <iostream>
#include <thread>
#include <future>
#include <memory>
using namespace std::literals::chrono_literals;
/**
 * 指定返回的promise结果类型为string类型
 */
void Promise1(std::promise<std::string> p);
void testPromise1();
