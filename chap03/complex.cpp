#include "complex.h"
#include <iostream>

complex::complex() {
    re = 0;
    im = 0;
}

complex::complex(double x) {
    re = x;
    im = 0;
}

complex::complex(double x, double y) {
    re = x;
    im = y;
}

double complex::real() const { return re; }
double complex::imag() const { return im; }
void complex::real(double x) { re = x; }
void complex::imag(double y) { im = y; }

complex& complex::operator+=(complex z) {
    re += z.re;
    im += z.im;
    return *this;
}

complex& complex::operator-=(complex z) {
    re -= z.re;
    im -= z.im;
    return *this;
}

complex& complex::operator*=(complex z) {
    double re_tmp = re * z.re - im * z.im;
    double im_tmp = re * z.im + im * z.re;

    re = re_tmp;
    im = im_tmp;

    return *this;
}

complex& complex::operator/=(complex z) {
    double den = z.re * z.re + z.im * z.im;
    if (den == 0) throw "Division by zero error!";

    double re_tmp = (re * z.re + im * z.im) / den;
    double im_tmp = (im * z.re - re * z.im) / den;

    re = re_tmp;
    im = im_tmp;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const complex& z) {
    return out << "(" << z.real() << ", " << z.imag() << ")";
}
