class Vector {
private:
    double* elem;
    int sz;
    
public:
    Vector(int);
    Vector(std::initializer_list<double>);
    ~Vector();
    double& operator[](int);
    int size() const;
};
