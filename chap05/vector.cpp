#include <iostream>
#include <stdexcept>
#include "vector.h"

Vector::Vector(int s)  {
    std::cout << "Constructor of Vector" << std::endl;
    if (s < 0) throw std::out_of_range("Index less than 0");

    elem = new double[s];
    sz = s;
    for (int i = 0; i < sz; ++i) elem[i] = 0;
}

Vector::Vector(std::initializer_list<double> l) {
    sz = l.size();
    elem = new double[sz];
    std::copy(l.begin(), l.end(), elem);
}

Vector::~Vector() {
    std::cout << "Destructor of Vector" << std::endl;
    delete[] elem;
}

/*
A copy constructor and a copy assignment for a class X are typically
declared to take an argument of type const X&. This implies that the
function itself will not be able to change the state of the object by means
of the reference that is passed to it as parameter. In addition, it won't
be possible to invoke member functions of the object through that reference
which are not themselves qualified as const.
*/
Vector::Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz} {
    for (int i = 0; i < sz; ++i) {
        elem[i] = a.elem[i];
    }
}

Vector& Vector::operator=(const Vector& a) {
    double* p = new double[a.sz];
    for (int i = 0; i < a.sz; ++i) {
        p[i] = a.elem[i];
    }

    // delete the resources held by this Vector
    delete[] elem;

    elem = p;
    sz = a.sz;
    return *this;
}

double& Vector::operator[](int s) {
    if (s < 0 || s > sz - 1) throw std::out_of_range("Index out of bounds");
    return elem[s];
}

int Vector::size() const {
    return sz;
}
