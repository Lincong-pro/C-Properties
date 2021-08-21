#pragma
#include <iostream>

template<typename T>
struct Position
{
	T x, y;
	Position(T x,T y) {
		this->x = x;
		this->y = y;
	}
};


std::ostream& operator<<(std::ostream& output,
	int* arr)
{
 	size_t length =	sizeof arr;
	output << length<<"\n";
	for (size_t i = 0; i < length / 4; ++i) {
		arr[i] += 1;
		output<<arr[i]<<" ";
	}
	output<<std::endl;
	return output;
}

void TypePunning1() {
	int a = 56;             //38 00 00 00
	double b = (double)a;   //00 00 00 00 00 00 4c 40 
	double d = *(int*)&a;   //00 00 00 00 00 00 4c 40 
	double e = *(double*)&a;//38 00 00 00 cc cc cc cc;  
	//Pre-statement maybe cause crash in some circumstances!It takes up the memory that doesn't belong to it;
	Position<int> f{ 1,2 };// initialize the Position        01 00 00 00 02 00 00 00
	int* arr = (int *)&f;	//obtain the address of f,and convert the content to int *
	std::cout << arr;


	int& ref = *(int*)((char*)arr + 4);//通过ref改变f.y
	ref = 7;
	std::cout << arr;

	int* _pointer = &f.x;//获取f.x所在的地址，然后就可以使用该地址变为数组形似操作

	std::cin.get();
}