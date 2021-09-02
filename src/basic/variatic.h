#pragma
#include <bitset>
#include <iostream>

//处理参数为0的情况
void println() { std::cout << "\n"; }

//递归进行输出
template <typename T, typename... Types> void println(T cur_arg, Types... args) {
    std::cout << cur_arg << " ";
    println(args...);
}

//更广泛的表达方式,下面调用的时候选择的是特化的一种
template <typename... T> void println(T... args) {
    println(args...);
    std::cout << args << " ";
}

void variaticTemplate1() { println(1, 4.5, std::bitset<16>(377), "lincong"); }

//模仿C语言的输出

void _printf(const char *match) {
    //到了这里之后就检查用户是否多匹配了%
    while (*match) {
        const char tmp1 = *match;
        const char tmp2 = *(++match);
        if (*match == '%' && *(++match) != '%') {
            throw std::runtime_error("invalid format string:missing arguments!");
        }
        std::cout << *(match);
    }
}

template <typename T, typename... Types> void _printf(const char *match, T arg1, Types... args) {
    //通过在match字符串中寻找%进行模拟输出
    while (*match) {
        if (*match == "%" && *(++match) != "%") {
            //将字符串输出
            std::cout << T;
            _printf(++match); //将字符再次后移
        }
        //如果不是以%开头就直接进行输出并后移
        std::cout << *(match++);
    }
}
