#include "_promise.h"
#include "functor.h"
#include "mytemplate.h"
#include "tuple.h"
#include "vector_insert.hpp"
#include "xthread.hpp"
#include <string>
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

    testVectorInsert();
    return 0;
}
