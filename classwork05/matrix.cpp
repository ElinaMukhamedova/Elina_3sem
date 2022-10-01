//
//  matrix.cpp
//  
//
//  Created by Elina Mukhamedova on 01.10.2022.
//

#include <iostream>

template<typename Field, size_t M, size_t N>
class Matrix {
private:
    Field a[M][N];
public:
    
    
    void print() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                std::cout << this->a[i][j] << " ";
            std::endl;
        }
    }
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                this->a[i][j] += other.a[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                this->a[i][j] -= other.a[i][j];
        return *this;
    }
    Matrix operator*(const Matrix& other) {
        Matrix mult;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                this->a[i][j] += other.a[i][j];
        return *this;
    }
};

//template<typename Field, size_t M, size_t N, size_t K>
//Matrix<Field, M, N> operator*(const Matrix<Field, M, N>& lha, const Matrix<Field, N, K>& rha) {
//
//}

int main() {
    for
    return 0;
}
