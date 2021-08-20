#pragma 
#include <chrono>
#include <iostream>
#include <thread>

/**
 * 简单使用
 */
void TestTime() {
	std::chrono::steady_clock::time_point _start = std::chrono::high_resolution_clock::now();
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
	std::chrono::steady_clock::time_point _end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> killtime = _end - _start;
	std::cout << "During time is " << killtime.count() << "\n";
}

//其实不用 /utf-8反而不会出现乱码
/**
 * 结构体封装
 */

struct Timing
{
private:
	std::chrono::steady_clock::time_point _start;
	std::chrono::steady_clock::time_point _end;
	std::chrono::duration<double> killtime;
public:
	Timing() {
		_start = std::chrono::high_resolution_clock::now();
	}
	~Timing() {
		_end = std::chrono::high_resolution_clock::now();
		killtime = _end - _start;
		std::cout << "Kill Time in all is " << killtime.count() << "\n";
	}
};
/**
 * 高阶使用方法
 */
void AdvanceTestTime() {
	Timing timer;//定时器开始记时间
	using namespace std::chrono_literals;
	for (int i=0; i < 10; ++i) {
		std::this_thread::sleep_for(1s);
	}
}