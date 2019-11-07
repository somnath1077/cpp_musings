#include <iostream>
#include <vector>
#include <assert.h>
#include "complex.h"

double integrate_func(double func(double), double left, double right, double steps = 1e-3) {
    // we are assuming that func is defined in the interval (left, right)
    std::vector<double> func_vals;
    assert(right - left >= 0);
    for (double x = left; x < right; x += steps)
        func_vals.push_back(func(x) * steps);

    double sum_of_elems = 0;
    for (auto& n : func_vals)
           sum_of_elems += n;
    return sum_of_elems;
}

double f(double x) {
    return x;
}

int main()
{
    double integrand = integrate_func(f, 0, 1, 1e-6);
    std::cout << "The value of the integral is " << integrand << std::endl;

    complex z1(1, 1);
    complex z2(2, 2);
    z1 += z2;

    std::cout << z1 << std::endl;
    // std::cout << z1.imag() << std::endl;
    return 0;
}
