//
//  C-Fractions.cpp
//  
//
//  Created by Elina Mukhamedova on 05.11.2022.
//

#include <stdio.h>
#include <cstdint>

class Fraction final {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template <class T>
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs) {}
    Fraction& operator=(const Fraction& rhs);
    Fraction(int64_t numerator, uint64_t denominator);
    // Your code goes below!
    // Add operators overload here
    Fraction& operator+=(const Fraction& other) {
        if ((this->denominator) == (other.denominator))
            this->numerator += other.numerator;
        else {
            this->numerator = (this->numerator) * (other.denominator) + (this->denominator) * (other.numerator);
            this->denominator = (this->denominator) * (other.denominator);
        }
        return *this;
    }
    
    Fraction& operator-=(const Fraction& other) {
        if ((this->denominator) == (other.denominator))
            this->numerator -= other.numerator;
        else {
            this->numerator = (this->numerator) * (other.denominator) - (this->denominator) * (other.numerator);
            this->denominator = (this->denominator) * (other.denominator);
        }
        return *this;
    }
    
    Fraction& operator*=(const Fraction& other) {
        this->numerator *= other.numerator;
        this->denominator *= other.denominator;
        return *this;
    }
    
    Fraction operator+(const Fraction& other) const{
        Fraction sum = *this;
        sum += other;
        return sum;
    }
    
    Fraction operator-(const Fraction& other) const {
        Fraction dif = *this;
        dif -= other;
        return dif;
    }
};
