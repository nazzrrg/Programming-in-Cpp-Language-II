#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H


#include <cstdint>
#include <vector>

class Matrix {
private:
    size_t size;
    std::vector<std::vector<double>> mat;
public:
    Matrix();
    Matrix(double, size_t);
    friend std::ostream& operator<< (std::ostream&, Matrix&);
    friend void mat_mult(Matrix&, size_t);
    friend void mat_mult(Matrix*, size_t);
};

#endif //LAB1_MATRIX_H
