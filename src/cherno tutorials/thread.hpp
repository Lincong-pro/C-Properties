#pragma 
#include <iostream>
#include <thread>

void another_thread(int x) {
	using namespace std::chrono_literals;
	//编码的bug会在第一次在vscode识别之后就可以在visual studio进行中文注释
	std::this_thread::sleep_for(1s);
	std::cout << "Hello\n";
}
