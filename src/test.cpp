#include <iostream>
#include <omp.h>
#include "test.h"


double test::fun(double x) {
    return 4.0 / (1.0 + x * x);
}

void test::testomp(const int num_steps) {

    double sum = 0.0, pi = 0.0, x;
    const double step = 1.0 / num_steps;
    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        sum += fun(x);
    }

    double end = omp_get_wtime();
    print("result: pi=");
    print(sum * step);
    print("time used:");
    print(end - start);
}

void test::testomp(const int num_steps, const int n) {

    double sum = 0.0, pi = 0.0, x;
    const double step = 1.0 / num_steps;
    double start = omp_get_wtime();
    omp_set_dynamic(0);
    omp_set_num_threads(n);
    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        sum += fun(x);
    }

    double end = omp_get_wtime();
    print("result: pi=");
    print(sum * step);
    print("time used:");
    print(end - start);
}
