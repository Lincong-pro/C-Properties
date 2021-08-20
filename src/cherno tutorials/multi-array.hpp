// 主要介绍关于多维数组的实质
#pragma 
#include "timing.hpp"

/**
 * 创建二维数组
 */
void Create2Array(const int _SIZE) {
	Timing timer;
	int** a2d = new int* [_SIZE];//just assign the pointer memory,but not the sub array
	for (int i = 0; i < _SIZE; ++i) {
		a2d[i] = new int[_SIZE];//assign the sub array
	}
	for (size_t i=0;i<_SIZE;++i)
	{
		for (size_t j = 0; j < _SIZE; j++)
		{
			a2d[i][j] = 0;
		}
	}
	for (int i = 0; i < _SIZE; ++i) {
		delete[] a2d[i];//release the sub array
	}
	delete[] a2d;//release the pointer
}

void CreateArray(const int _SIZE) {
	Timing timer;
	int* ad = new int[_SIZE * _SIZE];
	for (int i=0;i<_SIZE*_SIZE;++i)
	{
		ad[i] = 0;//Initializing
	}
	delete[] ad;
}
