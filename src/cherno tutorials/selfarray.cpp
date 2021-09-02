#include "selfarray.h"

void testArray() {
    Array<int, 3> arr;
    ////下面是将其设初值的方法
    // for (int i = 0; i < arr.Size(); ++i) {
    //    arr[i] = 3;
    //}
    //系统内置赋初值的方法
    memset(&arr[0], 0, arr.Size() * sizeof(int)); //只能初始化为0 -1
    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    constexpr int b = 5;
    int a[b]; // be careful that the size of an array must be a constant!

    // declare an array
    const size_t len = 1; // size_t len = 5;//error
    Array<std::string, len> data;
    data[0] = "lincong";
    const auto &ref = data;
    std::cout << "use the ref to print data:" << data[0] << std::endl;
}
