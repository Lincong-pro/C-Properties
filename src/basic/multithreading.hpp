#pragma
#include <iostream>
#include <thread>
//引入定时器
#include "timing.hpp"
#include <mutex>
#include <vector>

// print1
void print1(int n, const std::string &str) {
    std::cout << "Current thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
    volatile int cnt = 0; // 声明一个不能优化的变量，即下面for循环的变量是不能优化的
    for (int i = 0; i < 10000000000; ++i) {
        cnt += 1;
    }
}
bool flag = true;

void print3(int n, const std::string &str) {
    std::cout << "Current thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
    volatile int cnt = 0; // 声明一个不能优化的变量，即下面for循环的变量是不能优化的
    for (int i = 0; i < 1000000000; ++i) {
        cnt += 1;
        if (!flag) {
            break;
        }
    }
}

// print2 call print1
void print2(int n, const std::string &str) {
    std::cout << "Current thread: " << std::this_thread::get_id() << std::endl;
    print1(10, "Educative.blog");
}

// 在另外一个函数中开启两个线程以同步的方式进行执行
void testThreadPrintSync() {
    Timing timer; //开始记时
    std::thread t1(print1, 10, "Educative.blog");
    /**
     * Without join() here, the main thread would finish its task before t1 would complete print,
     * resulting in an error.
     */
    t1.join(); //该函数所在的线程结束的前提就是t1线程结束，如果没有这一句就会报错
    //主线程在此处等待t1完成
    std::cout << "t1 finished\n";
    std::thread t2(print2, 10, "Educative.blog");
    t2.join();
    //主线程在此处等待t2完成
    std::cout << "t1 finished\n";
}

// 在另外一个函数中开启两个线程以异步的方式进行执行
//忽略主函数的执行逻辑，理论上应该是异步时间最长的那个任务代表整个执行时间
void testThreadPrintAsync() {
    Timing timer; //开始记时
    std::thread t1(print1, 10, "Educative.blog");
    /**
     * Without join() here, the main thread would finish its task before t1 would
     * complete print, resulting in an error.
     */

    std::thread t2(print2, 10, "Educative.blog");
    std::thread t3(print2, 10, "Educative.blog");
    t1.join(); //该函数所在的线程结束的前提就是t1线程结束，如果没有这一句就会报错
    //主线程在此处等待t1完成
    std::cout << "t1 finished\n";
    t2.join();
    //主线程在此处等待t2完成，如果已经完成直接跳过进入下面的语句
    std::cout << "t2 finished\n";
    t3.join();
    std::cout << "t3 finished\n";
}

// 以守护线程的方式进行运行（更高效）-- 但是detach线程是不可以操作主线程数据的
void testThreadPrintAsyncEfficiency() {
    //该种方法记录时间特别麻烦，detach好处就是可以不用等待子线程的执行继续执行主函数的逻辑
    std::thread t1(print1, 10, "Educative.blog");
    /**
     * Without join() here, the main thread would finish its task before t1 would
     * complete print, resulting in an error.
     */

    std::thread t2(print2, 10, "Educative.blog");
    t1.detach(); //该函数所在的线程结束的前提就是t1线程结束，如果没有这一句就会报错
    //主线程在此处不会等待t1完成
    std::cout << "t1 executing\n";
    t2.detach();
    //主线程在此处不会等待t2完成
    std::cout << "t2 executing\n";
    //主函数结束但是依然后台线程还在运行
}

/**
 * 测试join方法退出等待的逻辑
 */
void testThreadPrintJoinEfficiency() {
    Timing timer; //开始记时
    std::thread t1(print3, 10, "Educative.blog");
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(0.5s); //主线程沉睡一秒之后等待子线程执行一秒
    flag = false;
    t1.join();
    //等待子线程完成
    //但是传入子线程退出.
}

// 单线程的方式执行上面的任务
void testSinglePrint() {
    Timing timer; //开始记时
    print1(10, "Educative.blog");
    print2(10, "Educative.blog");
}

void testMultiThreadPrint() {
    Timing timer;                     //开始记时
    std::vector<std::thread> threads; //模拟线程池
    std::vector<std::string> s = {"Educative.blog", "Educative", "courses"};
    for (int i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print1, i, s[i]));
    }

    // 主线程等待线程池中线程的完成
    for (auto &th : threads) {
        th.join();
    }
    // 返回支持 the number of concurrent threads supported by the implementation
    std::cout << std::thread::hardware_concurrency(); // CPU为4核4线程，所以显示是4
}

void printDivider() { std::cout << "==========================================\n"; }

/**
 * C++ thread参数传送内存分析
 */

class Lin {
public:
    Lin();
    Lin(const char *scope) {
        this->scope = scope;
        std::cout << "Create " + std::string(scope) + " Lin object in copy constructor !\n";
    }
    ~Lin();
    Lin(const Lin &lin1) {
        this->scope = "local";
        std::cout << "Create " + std::string(scope) + " Lin object in copy constructor!\n";
    }

public:
    const char *scope;
};

Lin::Lin() {
    this->scope = "local";
    std::cout << "Create " + std::string(scope) + " Lin object!\n";
}

Lin::~Lin() { std::cout << "Release " + std::string(scope) + " Lin object!\n"; }

//测试引用
void CopyLin(Lin &lin1) {
    // do nothing
    // 值传递的时候创建一个对象赋值给局部变量
    /************************************************************************/
    /* 意味着局部变量值传递释放一次，全局变量释放一次，参数拷贝释放一次                */
    /************************************************************************/
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
    printDivider();
    std::cout << lin1.scope << "\n";
}

//测试指针
void CopyLinPointer(Lin *lin1) {
    // do nothing
    // 值传递的时候创建一个对象赋值给局部变量
    /************************************************************************/
    /* 意味着局部变量值传递释放一次，全局变量释放一次，参数拷贝释放一次 */
    /************************************************************************/
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
    printDivider();
    std::cout << lin1->scope << "\n";
}
void CopyStringPointer(std::string *str) {
    // do nothing
    // 值传递的时候创建一个对象赋值给局部变量
    /************************************************************************/
    /* 意味着局部变量值传递释放一次，全局变量释放一次，参数拷贝释放一次 */
    /************************************************************************/
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
    printDivider();
    std::cout << *str << "\n";
}

void testMemoryOperation() {
    std::unique_ptr<std::thread> th = nullptr; //初始化线程但不进行函数指定，便于控制
    std::thread th1;
    {
        // Lin lin1("global");
        /*th = std::make_unique<std::thread>(CopyLin, lin1);*/
        // th1 = std::thread(CopyLin,lin1);
        // CopyLinPointer(&lin1);
        std::string str1("lincong");
        th = std::make_unique<std::thread>(CopyStringPointer, &str1);
    }
    //等待子线程完成任务，此时lin1对象已经传递进入
    th->join();
    // th1.join();
}