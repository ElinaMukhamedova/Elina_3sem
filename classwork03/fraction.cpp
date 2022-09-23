//
//  fraction.cpp
//  
//
//  Created by Elina Mukhamedova on 10.09.2022.
//

#include <iostream>
#include <cstdlib>

class Fraction {
public:
    friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);
    friend std::istream& operator>>(std::istream& is, Fraction& obj);
    
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
    
    Fraction operator*(const Fraction& other) const {
        Fraction mult = *this;
        mult *= other;
        return mult;
    }
    
    Fraction& operator++() {
          return *this += 1;
        }
        
    Fraction operator++(int k) {
        for (int i = 0; i < k; ++i)
            ++(*this);
        Fraction res = *this;
        return res;
    }
    
    Fraction& operator--() {
        return *this -= 1;
    }
    
    Fraction operator--(int k) {
        for (int i = 0; i < k; ++i)
            --(*this);
        Fraction res = *this;
        return res;
    }
    
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) { }
    Fraction(int numerator) : Fraction(numerator, 1) {}
    Fraction() = delete;
    Fraction(const Fraction& other) = default;  // : Fraction(other.numerator, other.denominator) { }
    
    void printFraction() {
        if ((numerator > 0 and denominator > 0) or (numerator < 0 and denominator < 0))
            std::cout << abs(numerator) << " / " << abs(denominator) << std::endl;
        else
            if (numerator != 0 and denominator != 0)
                std::cout << -abs(numerator) << " / " << abs(denominator) << std::endl;
            else
                if (denominator == 0)
                    std::cout << "division by 0" << std::endl;
                else
                    std::cout << 0 << std::endl;
    }
    void fracReverse() {
        int x = numerator;
        numerator = denominator;
        denominator = x;
    }
    void fracSimplify() {
        int a = abs(denominator);
        int b = abs(numerator);
        if (b < a) {
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
        this->numerator *= other.numerator;
        this->denominator *= other.denominator;
    }
    Fraction multByFracReturn(const Fraction& other) const {
        int new_numerator = this->numerator * other.numerator;
        int new_denominator = this->denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
            }
    void sumFrac(const Fraction& other) {
        int a = this->numerator;
        int b = this->denominator;
        this->numerator = a * other.denominator + b * other.numerator;
        this->denominator = b * other.denominator;
            }
    Fraction sumFracReturn(const Fraction& other) const {
        int a = this->numerator;
        int b = this->denominator;
        int new_numerator = a * other.denominator + b * other.numerator;
        int new_denominator = b * other.denominator;
        return Fraction(new_numerator, new_denominator);
            }
    void diffFrac(const Fraction& other) {
        int a = this->numerator;
        int b = this->denominator;
        this->numerator = a * other.denominator - b * other.numerator;
        this->denominator = b * other.denominator;
            }
    Fraction diffFracReturn(const Fraction& other) const {
        int a = this->numerator;
        int b = this->denominator;
        int new_numerator = a * other.denominator - b * other.numerator;
        int new_denominator = b * other.denominator;
        return Fraction(new_numerator, new_denominator);
            }
    double calc() {
        if (denominator != 0)
            return double(numerator) / double(denominator);
        else
            return 0;
    }
    int getNumerator() {
        return numerator;
            }
    int getDenominator() {
        return denominator;
            }
private:
    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    return out << '"' << fraction.numerator << ' ' << fraction.denominator << '"' << std::endl;
}
std::istream& operator>>(std::istream& is, Fraction& fraction) {
    return is >> fraction.numerator >> fraction.denominator;
}


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
    
    first.multByFrac(Fraction(3, 7));
    second.multByFrac(Fraction(5, 9));
    
    first.printFraction();
    second.printFraction();
    std::cout << std::endl;
    
    Fraction third = first.multByFracReturn(second);
    third.printFraction();
    std::cout << std::endl;
    
    first.fracSimplify();
    second.fracSimplify();
    third.fracSimplify();
    first.printFraction();
    second.printFraction();
    third.printFraction();
    std::cout << std::endl;
    
    Fraction fourth = Fraction(3, 7);
    fourth.diffFrac(Fraction(4, 2));
    fourth.printFraction();
    std::cout << std::endl;
    
    fourth.fracSimplify();
    fourth.printFraction();
    std::cout << fourth.calc() << std::endl;
    std::cout << std::endl;
    
    Fraction fifth = Fraction(1, 5);
    Fraction sixth = Fraction(2, 5);
    Fraction seventh = fifth.diffFracReturn(sixth);
    
    seventh.fracSimplify();
    seventh.printFraction();
    std::cout << seventh.calc() << std::endl;
    std::cout << std::endl;
    
    std::cout << seventh.getNumerator() << std::endl;
    std::cout << seventh.getDenominator() << std::endl;
    
    std::cout << seventh;
    
    Fraction eighth = Fraction(0);
    std::cin >> eighth;
    std::cout << eighth;
    
    seventh *= eighth;
    seventh.printFraction();
    
    eighth++;
    std::cout << eighth;
    
    Fraction ninth = eighth.operator--(5);
    std::cout << ninth;
    
    Fraction tenth = eighth.operator++(3);
    std::cout << tenth;
    
    std::cout << ninth + tenth << ninth - tenth << ninth * tenth;
}
