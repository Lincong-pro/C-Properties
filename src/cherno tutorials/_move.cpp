#include "_move.h"

Mystring::Mystring(const char *other) {
    printf("constructor char*\n");
    int len = strlen(other) + 1;
    this->len = len + static_cast<size_t>(1);
    this->str = new char[this->len];
    memcpy(this->str, other, len);
    this->str[len] = '\n';//添加结束符号
}

Mystring::Mystring(const Mystring &other) {
    printf("constructor&\n");
    if (this==&other)
    {
        //直接返回，不做后续操作
        return;
    }
    this->len = strlen(other.str); //求得数组的长度
    //字符数组赋值
    this->str = new char[len];
    //执行值的拷贝
    memcpy(this->str,other.str,this->len);
}

Mystring::~Mystring() {
    if (this->str != nullptr) {
        delete[] this->str;
    }
}

//R ref
Mystring::Mystring( Mystring&& other) {
    printf("constructor&&\n");
    //该构造函数主要用于move构造
    this->len = other.len;
    this->str = other.str;//直接引用同一个地址
    other.len = 0;
    other.str = nullptr;
}

Mystring &Mystring::operator=(const Mystring &other) {
    printf("operator=&\n");
    if (this == &other) {
        return *this; //直接返回自己
    }
    delete[] this->str; //释放空间---因为其是不可以进行改变
    len = other.len;
    str = new char[len];
    //执行值的拷贝
    memcpy(str, other.str, len);
    return *this;
}

Mystring &Mystring::operator= (Mystring&& other){
    printf("operator=&&\n");
    if (this == &other) {
        return *this; //直接返回自己
    }
    len = other.len;
    str = other.str;
    other.len = 0;
    other.str = nullptr;
    return *this;
}
void testString() {
    Mystring str1 = "lincong";//constructor *
    Mystring str4 = "lincong4";//constructor *
    str1 = str4;//constructor *  operator=
    Mystring str2(std::move(str1));//constructor &&
    Mystring str3 = "lincong";//constructor *
    str2 = std::move(str3);//operator= &&,实际上move相当于Mystring&& (Mystring&&)(str3)
}


size_t Mystring::length() { return this->len - 1; }