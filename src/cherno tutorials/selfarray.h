#pragma
#include <iostream>

//制作一个属于自己的array,在模板上指定具体的类型实际上指定的是不变量
template <typename T, size_t num> class Array {
public:
    //注意在栈中创建的数据结构远比堆中创建的数据结构快
    Array() { _size = num; }
    ~Array() = default;

public:
    T Size() { return _size; }
    /*利用[]进行数据操作（包括返回值/赋值）*/
    T &operator[](int index) {
        //如果想进行赋值必须返回引用才能保证是同一块地址操作
        return arr[index];
    }
    const T &operator[](int index) const {
        //如果想进行赋值必须返回引用才能保证是同一块地址操作
        return arr[index];
    }

private:
    T _size;
    T arr[num];
};

void testArray();