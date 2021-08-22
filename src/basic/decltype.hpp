#pragma
#include <iostream>
#include <map>
#include <set>

//情形1，delctype用于指定返回值类型

// function template declare
template<typename T1,typename T2>
//decltype(x + y) returnType(T1 x, T2 y); //这种写法错误，因为x，y还没有定义就使用
auto returnType(T1 x, T2 y);


// function template define
template <typename T1, typename T2>
//即便不写返回值类型，使用auto可以编译通过，但是通过lamda的方式指定返回值更快
auto returnType(T1 x, T2 y) -> decltype(x+y) {
  return x + y;
}


//情形二，用在模板函数中推断T类型
/**
 * 请输入容器类型
 */ 
template<typename T>
void test18_decltype(T obj) {
  std::map<std::string, float> coll;
  decltype(coll) map1(coll);//获取coll的类型并调用coll进行初始化
  typedef decltype(obj)::iterator iType;//保证该语句的前提是用户传入的是容器 
  for (iType i = obj.begin(); i != obj.end();++i) {
    std::cout << *i << " ";
  }
  std::cout << "\n";
}

void testMain1() { 
  std::vector<int> v(10);//赋予10个int空间
  v ={0,0,0};
  //接下来进行测试
  test18_decltype(v);//自动推断类型
}


class Person {
 public:
  char* firstname;
  char* lastname;
  Person() = default;
  Person(char* firstname, char* lastname) {
    this->firstname = (firstname);
    this->lastname = (lastname);
  }
};
//情形三，用于判断lamda表达式的类型

//下面的情况很难判断lamda表达式的类型
auto cmp = [](Person& p1, const Person& p2)->bool {
  return p1.lastname == p2.lastname && p1.firstname < p2.firstname ||
         p1.lastname < p2.lastname;
};

void testMain2() { 
    std::set<Person, decltype(cmp)> p(cmp); 
    //p.insert(Person("lin", "hao"));
    //for (Person it : p) {
    //  std::cout << it.firstname << " " << it.lastname << "\n";
    //}
}