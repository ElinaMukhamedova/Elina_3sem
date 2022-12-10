#include "grid.h"
#include <cassert>

void testIndexing() {
    Grid<std::string, 2> g(3, 2, "x");
    assert(g.get_size<1>() == 3);
    assert(g.get_size<2>() == 2);
    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 2; j++) {
            assert(g[i][j] == "x");
        }
    }
    std::cout << "Test testIndexing passed" << std::endl;
}

void testDefault() {
    Grid<double, 3> g(5, 2, 7, 0);
    assert(g.get_size<1>() == 5);
    assert(g.get_size<2>() == 2);
    assert(g.get_size<3>() == 7);
    for (unsigned i = 0; i < 5; i++) {
        for (unsigned j = 0; j < 2; j++) {
            for (unsigned k = 0; k < 7; k++) {
                assert(g[i][j][k] == 0.0);
                assert(g(i, j, k) == 0.0);
            }
        }
    }
    g[1][1][1] = 2;
    assert(g(1, 1, 1) == 2);
    std::cout << "Test testDefault passed" << std::endl;
}

void testMI() {
    Grid<float, 3> const g3(2, 3, 4, 1.0);
    assert(1.0 == g3(1, 1, 1));
    Grid<float, 2> g2(2, 5, 2.0f);
    assert(2.0f == g2(1, 1));
    g2 = g3[1];
    assert(1.0f == g2(1, 1));
    std::cout << "Test testMI passed" << std::endl;
}

void testConstructor() {
    Grid<float, 3> g1(1, 2, 3);
    assert(g1[0][1][2] == 0.0f);
    Grid<float, 3> g2(1, 2, 3, 239.f);
    assert(g2[0][1][2] == 239.f);

    Grid<int, 2> g3(15);
    assert(g3.get_size<1>() == 1);
    assert(g3.get_size<2>() == 1);
    assert(g3(0, 0) == 15);
    std::cout << "Test testConstructor passed" << std::endl;
}

int main() {
    testIndexing();
    testDefault();
    testMI();
    testConstructor();
    return 0;
}
