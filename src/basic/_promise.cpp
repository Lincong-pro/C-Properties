#include "_promise.h"


void Promise1(std::promise<std::string> p) {
  for (int i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(100ms);
    std::cout << "." << std::flush;  //将缓存中的string刷新到控制台进行显示
  }
  std::cout << "\nwaiting ...\n";
  std::this_thread::sleep_for(2s);
  p.set_value("lincong喔!");  //向外界传递值
  std::this_thread::sleep_for(2s);
}
/**
 * 测试Promise1
 */
void testPromise1() {
  std::promise<std::string> p;
  std::unique_ptr<std::thread> th = nullptr;
  //获取future对象----一定要在传入thread之前获取，不然无法通过future获取值
  std::future future_obj = p.get_future();
  //在任意时间指定线程的创建(注意move，目的是让string只构造一次)
  th = std::make_unique<std::thread>(Promise1, move(p));
  std::cout << future_obj.get() << "\n";  //主线程等待子线程返回值
  th->join();                             //主线程等待子线程
}