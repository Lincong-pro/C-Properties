#pragma 
#include "thread.hpp"
#include "multi-array.hpp"
#include "sortAlgorithm.hpp"
#include "type_punning.hpp"
#include "union.hpp"
int main(int argc,char* argv[]) {
	//TestTime();
	//AdvanceTestTime();

	// first param is thread method,and the other param is a type of Type...
	//std::thread worker(another_thread,1);//参数可以随便递增
	//worker.join();//主线程等待其完成

	//CreateArray(5000);
	//Create2Array(5000);// kill more time


	//TypePunning1();

	testUnion();

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}