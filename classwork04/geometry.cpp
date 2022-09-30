//
//  geometry.cpp
//  
//
//  Created by Elina Mukhamedova on 24.09.2022.
//

#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    double operator-(const Point* other) const {
        double length = sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
        return length;
    }
private:
    double x;
    double y;
};

class Shape {
public: // Объявите методы area, perimeter, center
    virtual double perimeter() {
        int n = storage.size();
        double ans = 0;
        for (int i = 1; i < n; ++i)
            ans += storage.at(i) - storage.at(i - 1);
        ans += storage.at(n - 1) - storage.at(0);
        return ans;
    }
protected:
    std::vector<Point> storage;  // хранилище угловых точек для фигуры
};

class Triangle: public Shape {
    double perimeter() override {}
};

int main() {
    
    return 0;
}
