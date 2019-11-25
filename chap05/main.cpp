#include <iostream>
#include "vector.h"

int main() {
    Vector v = {1, 2, 3, 4};
    std::cout << v.size() << std::endl;
    v.print();
    v[1] = 10;
    v.print();
    return 0;
}
