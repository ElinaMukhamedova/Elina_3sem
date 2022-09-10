//
//  fraction.cpp
//  
//
//  Created by Elina Mukhamedova on 10.09.2022.
//

#include <iostream>

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) { }
    Fraction(int numerator) : Fraction(numerator, 1) {}
    Fraction() = delete;
    Fraction(const Fraction& other) = default;  // : Fraction(other.numerator, other.denominator) { }
    
    void printFraction() {
        std::cout << numerator << " / " << denominator << std::endl;
    }
    void fracReverse() {
        int x = numerator;
        numerator = denominator;
        denominator = x;
    }
    void fracSimplify() {
        int a = denominator;
        int b = numerator;
        if (numerator < denominator) {
            a = numerator;
            b = denominator;
        }
        int gcd = a;
        bool flag = false;
        while (flag == false) {
            if ((a % gcd == 0) and (b % gcd == 0))
                flag = true;
            else {
                b = b - a;
                if (b < a) {
                    int c = a;
                    a = b;
                    b = c;
                }
                gcd = a;
            }
        }
        if ((numerator % gcd == 0) and (denominator % gcd == 0)) {
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }
    }
    void multByNumber(int value) {
        numerator *= value;
    }
    void multByFrac(const Fraction& other) {
        
    }
    
private:
    int numerator;
    int denominator;
};


int main() {
    Fraction first = Fraction(13, 20);
    Fraction second = first;
    
    first.printFraction();
    second.printFraction();
    std::cout << std::endl;
    
    first.multByNumber(5);
    second.multByNumber(7);
    
    first.printFraction();
    second.printFraction();
    std::cout << std::endl;
    
    first.fracReverse();
    second.fracReverse();
    
    first.printFraction();
    second.printFraction();
    std::cout << std::endl;
    
    first.fracSimplify();
    second.fracSimplify();
    
    first.printFraction();
    second.printFraction();
    std::cout << std::endl;
}
