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

void PrintValue(int &&a) { std::cout << "belong to rvalue!\n"; } //只能右值引用
// void PrintValue(const int& a) { std::cout << "belong to rvalue and lvalue!"; }
void PrintValue(int &a) { std::cout << "belong to lvalue!\n"; } //只能左值引用

// R-value传递
void forward(int &&a) { PrintValue(a); }
void testLvalueAndRvalueTransform() {
    int a = 56;
    PrintValue(a);       // l value
    PrintValue(5201314); // r value
    forward(200);        // r value -> l value(具名变量就变化为左值引用)
}