#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif


TwoDimensionMatrix::TwoDimensionMatrix() {
    matrix_[0][0] = 0;
    matrix_[1][0] = 0;
    matrix_[0][1] = 0;
    matrix_[1][1] = 0;
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement (*matrix)[2]) {
    matrix_[0][0] = matrix[0][0];
    matrix_[0][1] = matrix[0][1];
    matrix_[1][0] = matrix[1][0];
    matrix_[1][1] = matrix[1][1];
}
MatrixElement TwoDimensionMatrix::get(MatrixElement row, MatrixElement column) const {
    return this->matrix_[row][column];
}

MatrixElement* TwoDimensionMatrix::operator[](std::size_t position) {
    return matrix_[position];
}

const MatrixElement* TwoDimensionMatrix::operator[](std::size_t position) const{
    return matrix_[position];
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix matrix) {
    for(int i=0; i<size_; i++) {
        for(int j=0; j<size_; j++) {
            matrix_[i][j] = matrix.get(i, j);
        }
    }
    return *this;
}

ostream& operator<<(ostream &os, const TwoDimensionMatrix matrix) {
    os << matrix[0][0] << matrix[0][1] << endl;
    os << matrix[1][0] << matrix[1][1] << endl;
    return os;
}

istream& operator>>(istream &is, TwoDimensionMatrix& matrix) {
    for (int i=0; i<TwoDimensionMatrix::size_; i++) {
        for(int j=0; j<TwoDimensionMatrix::size_; j++) {
            is >> matrix.matrix_[i][j];
        }
    }
    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    TwoDimensionMatrix resultMatrix;
    for (int i=0; i<TwoDimensionMatrix::size_; i++) {
        for(int j=0; j<TwoDimensionMatrix::size_; j++) {
            resultMatrix.matrix_[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return resultMatrix;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const {
    TwoDimensionMatrix resultMatrix;
    for (int i=0; i<TwoDimensionMatrix::size_; i++) {
        for (int j = 0; j < TwoDimensionMatrix::size_; j++) {
            resultMatrix.matrix_[i][j] = this->matrix_[i][j] && matrix.matrix_[i][j];
        }
    }
    return resultMatrix;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (int i = 0; i < TwoDimensionMatrix::size_; i++) {
        for (int j = 0; j < TwoDimensionMatrix::size_; j++) {
            matrix_[i][j] *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix::operator size_t() const {
    return TwoDimensionMatrix::size_;
}



