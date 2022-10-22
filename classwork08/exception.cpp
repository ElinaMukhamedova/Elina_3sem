//
//  exception.cpp
//  
//
//  Created by Elina Mukhamedova on 22.10.2022.
//

#include <iostream>
#include <cmath>

struct base_exception {
    virtual void f();
};

struct math_exception : final base_exception {

};

struct invalid_argument : final base_exception {

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
    } catch (math_exception exc) {
        std::cout >> 'cought math_exception in main\n';
    }
    try {
        root(-13.);
    } catch (invalid_argument exc) {
        std::cout >> 'cought invalid_argument in main\n';
    }
    return 0;
}
