//
//  rectangles.cpp
//  
//
//  Created by Elina Mukhamedova on 17.09.2022.
//

#include <iostream>

class Point {
public:
    unsigned long long const x, y;
    Point(unsigned long long x, unsigned long long y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    Point minx(const Point &rha) const {
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(const Point &rha) const {
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx(const Point &rha) const {
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy(const Point &rha) const {
        return Point(x, rha.y > y ? rha.y : y);
    }
    void print() const {
        std::cout << '(' << x << " ; "  << y << ')' << std::endl;
    }
};

class Rectangle {
public:
    Rectangle(Point const &vertex) : vertex(vertex) {}
    Rectangle() : Rectangle(Point()) {}
    Rectangle operator+(const Rectangle &rha) const {
        Point maxx_point = this->vertex.maxx(rha.vertex);
        Point maxy_point = this->vertex.maxy(rha.vertex);
        int x = maxx_point.x;
        int y = maxy_point.y;
        Point new_vertex = Point(x, y);
        Rectangle new_rectangle = Rectangle(new_vertex);
        return new_rectangle;
    }
    Rectangle operator*(const Rectangle &rha) const {
        Point minx_point = this->vertex.minx(rha.vertex);
        Point miny_point = this->vertex.miny(rha.vertex);
        int x = minx_point.x;
        int y = miny_point.y;
    }
    Point getVertex() {
        return vertex;
    }
private:
    Point vertex;
};

int main() {
    Point A = Point(2, 3);
    Point B = Point(4, 5);
    Rectangle first = Rectangle(A);
    Rectangle second = Rectangle(B);
    Rectangle third = first + second;
    first.getVertex().print();
    second.getVertex().print();
    third.getVertex().print();
    return 0;
}
