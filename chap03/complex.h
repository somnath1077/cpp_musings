#ifndef COMPLEX_H
#define COMPLEX_H
#include <iosfwd>

class complex
{
    double re, im;

    public:
        complex();
        complex(double);
        complex(double, double);

        double real() const;
        double imag() const;

        void real(double);
        void imag(double);

        complex& operator+=(complex);
        complex& operator-=(complex);
        complex& operator*=(complex);
        complex& operator/=(complex);
};

std::ostream& operator<<(std::ostream&, const complex&);

#endif // COMPLEX_H
