#include "variatic.hpp"
#include "multithreading.hpp"
int main() { 
    //variaticTemplate1();


    //线程
    testThreadPrintSync();
    printDivider();
    testThreadPrintAsync();
    printDivider();
    testSinglePrint();
    printDivider();
    testThreadPrintJoinEfficiency();
    return 0; 
}
