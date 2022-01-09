#pragma
#include <stdio.h>
#include <string.h>
#include <type_traits>
class Mystring {
public:
    Mystring(const char *other);
    // R ref
    Mystring(const Mystring &other);

    ~Mystring();
    // L ref
    Mystring(Mystring &&other);

    Mystring &operator=(const Mystring &other);
    // move assign
    Mystring &operator=(Mystring &&other);

    size_t length();
    char *str = nullptr;

private:
    size_t len = 0;
};

void testString();

void moveTest();