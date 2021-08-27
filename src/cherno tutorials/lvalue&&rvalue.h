#pragma 
#include <iostream>
//主要用于测试lvalue和rvalue
void testLvalueAndRvalue();
int GetRvalue();
void PrintValue(int&& a);//rvalue cannot be initial by lvalue
//void PrintValue(const int& a);
void PrintValue(int& a);