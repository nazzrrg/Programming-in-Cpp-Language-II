#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {
    size = 3;
    mat.resize(size);
    for (auto& v : mat) {
        v.resize(size);
    }
}\
Matrix::Matrix(double val, size_t n) {
    size = n;
    mat.resize(size);
    for (auto& v : mat) {
        v.resize(size);
        for (auto& item : v) {
            item = val;
        }
    }
}

std::ostream& operator<<(std::ostream& out, Matrix& x) {
    for (size_t i = 0; i < x.size; i++) {
        for (size_t j = 0; j < x.size; j++) {
            out << x.mat[i][j] << ' ';
        }
        out << std::endl;
    }

    return out;
}

void mat_mult(Matrix& m, size_t scal) {
    for (auto& v : m.mat) {
        for (auto& i : v){
            i *= scal;
        }
    }
}
void mat_mult(Matrix* m, size_t scal) {
    for (auto& v : m->mat) {
        for (auto& i : v){
            i *= scal;
        }
    }
}
