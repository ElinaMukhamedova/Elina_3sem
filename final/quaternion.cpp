//
//  quaternion.cpp
//  
//
//  Created by Elina Mukhamedova on 17.12.2022.
//

#include <iostream>
#include <cstdlib>
#include <iomanip> //setw() //showpos()


template <typename T>
class Quaternion {
private:
    T A;
    T B;
    T C;
    T D;
public:
    Quaternion(T a, T b, T c, T d) : A(a), B(b), C(c), D(d) {}
    Quaternion(T a) : Quaternion(a, 0, 0, 0) {}
    Quaternion() = delete;
    Quaternion(const Quaternion& other) = default;

    T norm() {
        T s2 = A * A + B * B + C * C + D * D;
        return s2;
    }
    
    void printQuaternion() {
        std::cout << A;
        std::cout << std::showpos<< B << "i";
        std::cout << std::showpos<< C << "j";
        std::cout << std::showpos<< D << "k";
        std::cout << std::endl;
    }
    
    void inverse() {
        T s2 = norm();
        if (s2 != 0) {
            A = A / s2;
            B = -B / s2;
            C = -C / s2;
            D = -D / s2;
        }
    }
    
    Quaternion inverseQuaternion() {
        T s2 = norm();
        if (s2 != 0)
            return Quaternion(A / s2, -B / s2, -C / s2, -D / s2);
    }
};

int main() {
    Quaternion<double> first = Quaternion<double>(1, 1, 1, 1);
    first.printQuaternion();
    first.inverse();
    first.printQuaternion();
    Quaternion<double> First = first.inverseQuaternion();
    First.printQuaternion();
    
    return 0;
}
