class Vector {
private:
    double* elem;
    int sz;

public:
    Vector(int);
    Vector(std::initializer_list<double>);
    ~Vector();

    Vector(const Vector&); // copy constructor;
    // the const promises that the vector passed in as parameters will not be modified
    Vector& operator=(const Vector&); // copy assignment

    double& operator[](int);
    int size() const;
};
