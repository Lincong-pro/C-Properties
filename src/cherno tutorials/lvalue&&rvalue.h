#pragma
#include <iostream>
//主要用于测试lvalue和rvalue
void testLvalueAndRvalue();
int GetRvalue();
// rvalue cannot be initial by lvalue
void PrintValue(int &&a);
// void PrintValue(const int& a);
void PrintValue(int &a);

//苏大炳-----------介绍右值引用和左值引用之间的转化
/*
 * 编译器会将已命名的右值引用视为左值，将未命名的右值引用视为右值
 * 通过右值推导T&&或者auto&&得到的是一个右值引用类型，其余都是左值引用类型
 */
void forward(int &&a);
void testLvalueAndRvalueTransform();