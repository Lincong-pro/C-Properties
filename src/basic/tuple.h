#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
template <typename... Values> class Tuple;

template <> class Tuple<> {};

template <typename Head, typename... Tail> class Tuple<Head, Tail...> : public Tuple<Tail...> {
    typedef Tuple<Tail...> inherited; //简写父类类型

public:
    Tuple() {}
    Tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

    inherited &tail() { return *this; } //强制转化为inherited类型

    typename Head head() { return m_head; }

protected:
    Head m_head;
};
template <typename Head> void output_static_data(Head head) { std::cout << " " << head << " \n"; }
template <typename Head, typename... T> void output_static_data(Head head, T... args) {
    //递归进行输出
    std::cout << " " << head;
    output_static_data(args...);
}

////实现模板的模板,其中 Container的类型可以根据T的类型进行推断
// template <typename T, template <class> class Container> class XCIs1 {
// public:
//    XCIs1() {
//        // constructor
//        for (long i = 0; i < 10; ++i) {
//            c.insert(c.end(), T());
//        }
//        output_static_data(T());
//        Container<T> c1(c);
//        Container<T> c2(std::move(c));
//        c1.swap(c2);
//    }
//    ~XCIs1() {}
//
// private:
//    Container<T> c; //将模板参数T作为模板的参数
//};
//
// template <typename T> using Vec = std::vector<T, allocator<T>>;
// XCIs1<int, Vec> c1;
