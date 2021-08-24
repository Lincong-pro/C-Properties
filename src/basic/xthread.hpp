// 将自己的工作函数封装为线程对象
#pragma
#include "multithreading.hpp"
#include <thread>
#include <memory>
#include <iostream>
#include <mutex> //call_once函数
using namespace std::chrono_literals;

class XThread {
 public:
    //工作函数，用于实现异步线程实现效果
  virtual void WorkerFun()=0;//要求子类继承于该类必须进行实现
  /**
   * 虚函数，启动线程进行工作
   */
  virtual void Start() { 
      SetFlag(false);
      // 创建线程对象
      worker =  std::make_unique<std::thread>(&XThread::WorkerFun,this);
      //初始化thread_id
      thread_id = worker->get_id();
  }
  /**
   * XThread线程对象的Wait函数实际上就是将子线程合并到主线程中
   */
  virtual void Wait() {
      if (worker->joinable())
      {
          //如果该线程有id，即可以合并
            worker->join();
      }
  }

  /**
   * 虚函数，用户可选择性进行重写
   */
  virtual void Stop() { 
      if (!flag)
      {
        SetFlag(true);//停止thread进行
      }
      Wait();//放入主线程中
  }
  XThread() = default;//采用默认的构造函数
  ~XThread() = default;//实际上也是什么都不需要做，因为thread对象已经被unique_ptr指针只能管理了
  
  bool GetFlag() { return flag; } 

 private:
  std::unique_ptr<std::thread> worker=nullptr;//初始化指针为空指针（C++11才有的特性）
  std::thread::id thread_id;
  bool flag = false;
  // 设置flag真假
  void SetFlag(bool f) { flag = f; }
};

 /**
 * 线程初始化部分
 */
void Init() { std::cout << "do some initial works!\n"; }
void InitOnce() {  //下面语句保证初始化函数只被call一次
  static std::once_flag flag;
  std::call_once(flag, Init);
}
//继承于XThread以便重写WorkerFun函数逻辑
class SubThread:public XThread {
 public:
  SubThread() = default;
  ~SubThread() = default;
  //override新关键字保证了重写的正确性
  void WorkerFun() override {
    InitOnce();//初始化一次
    InitOnce();//所以多call几次也没有意义
    for (int i = 0; i < 100000000; ++i) {
      std::this_thread::sleep_for(100ms);
      std::cout << "."<<std::flush;
      //该标志进入if语句内部代表用户停止thread运行
      if (GetFlag()) {
        std::cout << std::endl;
        break;
      }
    }
  }
};

void TestSubThread() { 
  Timing timer;
  SubThread th;
  th.Start();//启动线程函数
  std::this_thread::sleep_for(5s);
  th.Stop();//放入线程中
}


////手动模仿RAII
//class XMutex {
// public:
//  XMutex(std::mutex& mtx1):mtx(mtx1) {
//      std::cout << "mutex init\n";
//    mtx.lock();
//  }
//  ~XMutex() {
//    std::cout << "mutex unlock\n";
//    mtx.unlock();
//  }
//
// private:
//  std::mutex mtx;
//};