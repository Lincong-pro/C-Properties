#include <omp.h>
#include <stdio.h>

int fib(int n) {
    int i, j, result;
    if (n < 2) {
        result = n; //返回fib的前两个数字
    } else {
#pragma omp task shared(n) private(i)
        i = fib(n - 1);
#pragma omp task shared(n) private(j)
        j = fib(n - 2);
#pragma omp taskwait

        result = i + j;
    }
    return result;
}

int testFib() {
    int n = 16;
    int result;
    omp_set_dynamic(false);
    omp_set_num_threads(4);
    //clang-format off
    //clang-format on
#pragma omp parallel shared(n)
    {
        result = fib(n);
#pragma omp single
        printf("fib(%d)=%d\n", n, result);
    }
    return result;
}