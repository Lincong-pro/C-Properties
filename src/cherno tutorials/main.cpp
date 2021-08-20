#include <timing.hpp>
#include "thread.hpp"
int main(int argc,char* argcv[]) {
	//TestTime();
	//AdvanceTestTime();

	// first param is thread method,and the other param is a type of Type...
	std::thread worker(another_thread,1);//参数可以随便递增
	worker.join();//主线程等待其完成
	return 0;
}