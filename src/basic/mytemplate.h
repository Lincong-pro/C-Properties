#pragma
#include <iostream>
template <typename V, typename T, typename U> V add1(T data1, U data2) { return data1 + data2; }

template <typename T, typename U> auto add2(T data1, U data2) { return data1 + data2; }

//使用后置返回值,decltype+auto关键字
template <typename T, typename U> auto add3(T data1, U data2) -> decltype(data1 + data2) {
    std::cout << "Template Method!\n";
    return data1 + data2;
}

//当存在模板和实例函数的时候，模板推导使用模板而不是实例函数
auto add3(int data1, double data2) -> decltype(data1 + data2) {
    std::cout << "Instance Method!\n";
    return data1 + data2;
}

void testTemplateDeduce() {
    add1<double>(12, 12.7); //必须指定返回值类型才能进行推断，从中可以观察到的是模板参数可以只传递部分
    add2(12, 12.7);   //使用auto关键字代替模板参数的返回值
    add3<>(12, 12.7); //使用尖括号显示指定推导的类型为模板函数
}

//重载的模板方法-----主要体现在&，*,函数会自动寻找最匹配的方法进行调用
template <typename T, typename... Args> void overrideTemplateFunc(const T &arg1, Args... args) {
    std::cout << arg1 << " ";
    overrideTemplateFunc(args...);
}

template <typename T> void overrideTemplateFunc(const T &arg1) { std::cout << arg1 << "\n"; }
void testTemplateOverride() {
    const char *name = "lincong";
    overrideTemplateFunc(name, "I", "love you!");
}

//普通函数->特化->泛化

//模板的特化与偏特化
template <typename T, typename U> void showLove(const T *str1, const U str2) {
    std::cout << "Generalization\n";
    std::cout << str1 << "  and " << str2 << " be there!"
}

//全特化，即显示指定模板的样子，但是实际上全部指定参数,模板自动推导
template <> void showLove(const char *str1, const char *str2) {
    std::cout << "Full specialization \n";
    std::cout << str1 << "  and " << str2 << " be there!";
}

//函数模板是不能进行偏特化的，比如下面的做法就会报错
// template <> void showLove<double, U>(const char *str1, const U str2) {}
template <typename U> void showLove(const char *str1, const U str2) {
    std::cout << "模板函数的重载实现模拟偏特化" << std::endl;
}

//测试特化
void testSpecializition() { showLove<>("lin", "cong"); }

//模板类型的默认值指定

int sub(int a, int b) { return a + b; }

//指定函数指针的类型
typedef int (*FuncType)(int, int); //定义函数指针FuncType

//函数模板上还可以指定非模板参数,非模板参数只需要指明类型即可
template <typename _Tp, typename _Up, typename _func = FuncType>
auto addProxy(_Tp data1, _Up data2, FuncType func = add) {
    std::cout << "template parameter\n";
    return func(data1, data2);
}

//非模板参数可以位于任何地方,但是目前非类型模板参数支持度有限
//整型或者枚举型
//指针类型
//左值引用类型
// auto或者decltype(auto)
template <typename T, int a = 100> void nonTemplateParam() {
    T b = "str";
    std::cout << b << a << "\n";
}

void testFunc() {
    std::cout << addProxy(2, 3, &sub) << "\n";
    nonTemplateParam<char *, 110>();
}

/*模板中的模板*/
template <typename T, template <class> class Container> class XCIs {
private:
    Container<T> c; //声明一个容器

public:
    XCIs() { // constructor
        for (size_t i = 0; i < length; i++) {
            c.insert(c.end(), T());
        }
        output_static_data(T());
        Container<T>;
        c1(c);
        Container<T> c2(std::move(c));
        c1.swap(c2);
    }
    ~XCIs();

private:
};