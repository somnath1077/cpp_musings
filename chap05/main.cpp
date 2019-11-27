#include <iostream>
#include "vector.h"
#include "container.h"


class VectorContainer : public Container {
    Vector v;

    public:
        VectorContainer(int s) : v(s) {}

        VectorContainer(std::initializer_list<double> l) : v(l) {}

        ~VectorContainer() {
            std::cout << "Destructor of VectorContainer" << std::endl;
        }

        double& operator[](int i) { return v[i]; }
        int size() const { return v.size(); }
};


void use(Container& c) {
    int sz = c.size();
    for (int i = 0; i < sz; ++i)
        std::cout << c[i] << std::endl;
}

int main() {
    //VectorContainer v = {1, 2, 3, 4};
    //std::cout << v.size() << std::endl;
    //use(v);
    //v[1] = 10;
    //use(v);

    VectorContainer v2 = {1, 2, 3, 4};
    VectorContainer v3{v2};
    // use(v2);
    //use(v3);
    v3[1] = 1000;
    use(v2);
    use(v3);

    VectorContainer v4 = v3;
    use(v4);
    return 0;
}
