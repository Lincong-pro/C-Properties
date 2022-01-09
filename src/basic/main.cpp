#include "_promise.h"
#include "functor.h"
#include "mytemplate.h"
#include "tuple.h"
#include "xthread.hpp"
#include <fmt/format.h>
#include <iostream>
#include <string>
//////////////////////////////////////////////////////////////////////////
// 友元函数测试
//////////////////////////////////////////////////////////////////////////
class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    ~Point() = default;
    /****************************************************************************/
    /* 在类中声明为友元函数作用 ，可以直接在类中初始化，相当于在类外部进行cpp全局域初始化一样 */
    /****************************************************************************/
    friend Point operator+(Point &d1, Point &d2) { return Point(d1.x + d2.x, d1.y + d2.y); }
    friend std::ostream &operator<<(std::ostream &out, Point &point) {
        out << fmt::format("({},{})", point.x, point.y);
        return out;
    }
    double x;
    double y;
};

void FriendshipUsage() {
    Point p1(1, 3);
    Point p2(2, 6);
    Point p3 = p1 + p2;
    std::cout << p3;
}

#ifdef Success
// TODO 失败
/**
 * @brief 程序入口点测试
 * @param argc
 * @param argv
 * @return
 */
int Startup(int argc, char *argv[]) {
    int a = 10;
    HANDLE crtHeap = HeapCreate(HEAP_NO_SERIALIZE, 0x010, 4000 * 1024);
    int *p = (int *)HeapAlloc(crtHeap, HEAP_ZERO_MEMORY, 0x010);
    int i, j;

    for (i = 0; i < 100; ++i) {
        for (j = 0; j < 100; j++, p++) {
            *p = i * 100 + (j + 1);
        }
    }

    MessageBoxA(NULL, "55", "abcd", MB_OK);
    return 0;
}

#endif // Success

int main() {
    // variaticTemplate1();

    //线程
    // testThreadPrintSync();
    // printDivider();
    // testThreadPrintAsync();
    // printDivider();
    // testSinglePrint();
    // printDivider();
    // testThreadPrintJoinEfficiency();
    // testMemoryOperation();

    // TestSubThread();

    // testPromise1();

    // testThreadRef();

    // testTemplateDeduce();

    // testTemplateOverride();

    // testSpecializition();

    // testFunc();

    // Tuple<int, double, std::string> tuple1(12, 44.33, std::string("hello world"));

    FriendshipUsage();
    return 0;
}
