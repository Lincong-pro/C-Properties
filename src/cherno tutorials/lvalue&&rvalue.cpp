#include "lvalue&&rvalue.h"
void testLvalueAndRvalue() {
    int a = 10; // 10 is a temporary value
    // GetRvalue() = 4; //error,expression must be a modable lvalue
    a = GetRvalue(); //其中该函数返回的值属于Rvalue，临时变量，Rvalue有一个特点就是不可变的
    PrintValue(a);
    PrintValue(GetRvalue() + GetRvalue());
}

int GetRvalue() {
	int b = 10;
	return b;
}

void PrintValue(int &&a) { std::cout << "belong to rvalue!"; }//只能右值引用
//void PrintValue(const int& a) { std::cout << "belong to rvalue and lvalue!"; }
void PrintValue(int& a) { std::cout << "belong to lvalue!"; }//只能左值引用