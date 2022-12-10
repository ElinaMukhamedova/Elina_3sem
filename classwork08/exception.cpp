//
//  exception.cpp
//  
//
//  Created by Elina Mukhamedova on 22.10.2022.
//

#include <iostream>
#include <cmath>

struct base_exception {
    virtual void f() {
        std::cout << "base";
    }
};

struct math_exception : base_exception{
    void what() {
        std::cout << "cought math_exception";
    }
};

struct invalid_argument : base_exception{
    void what() {
        std::cout << "cought invalid_argument";
    }
};

double inverse(double x) {
  if (x == 0)
    throw math_exception();
  return 1. / x;
}

double root(double x) {
  if (x < 0)
    throw invalid_argument();
  return std::sqrt(x);
}

int main() {
    try {
        inverse(0.);
    } catch (math_exception &exc) {
        exc.what();
    }
    try {
        root(-13.);
    } catch (invalid_argument &exc) {
        exc.what();
    }
    return 0;
}
