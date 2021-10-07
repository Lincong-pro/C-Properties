// 测试emplace_back和push_back的区别
#pragma once

#include <iostream>
#include <vector>
using namespace std;
class testDemo {
public:
    testDemo(int num) : num(num) { std::cout << "调用构造函数" << endl; }
    testDemo(const testDemo &other) : num(other.num) { std::cout << "调用拷贝构造函数" << endl; }
    testDemo(testDemo &&other) : num(other.num) { std::cout << "调用移动构造函数" << endl; }

public:
    int num;
};
void testVectorInsert() {
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    // 只会封装一个临时对象，并不会进行移动
    demo1.emplace_back(2);
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    // push_back会封装一个临时对象，然后进行移动
    demo2.push_back(2);
}