//
//  l2.cpp
//  
//
//  Created by Elina Mukhamedova on 08.10.2022.
//

#include <iostream>
#include <random>

using State = int;

struct Base {
    virtual bool contains(State s) const = 0;
};

struct DiscreteState : Base{
private:
    State const s0;
public:
    DiscreteState(State s0) : s0(s0) {}
    virtual bool contains(State s) const override{
        return s == s0;
    }
};

struct SegmentState : Base{
private:
    State const begin_s0, end_s0;
public:
    SegmentState(State begin_s0, State end_s0) : begin_s0(begin_s0), end_s0(end_s0) {}
    virtual bool contains(State s) const override {
        return begin_s0 <= s and end_s0 >= s;
    }
};

struct Unite : Base {
private:
    std::vector<SegmentState> storage;
public:
    Unite(std::vector<SegmentState> storage) : storage(storage) {}
    virtual bool contains(State s) const override {
        int n = storage.size();
        bool f = false;
        for (int i = 0; i < n; ++i)
            if (storage.at(i).contains(s))
                f = true;
        return f;
    }
};

struct Intersect : Base {
private:
    std :: vector<SegmentState> storage;
public:
    Intersect(std::vector<SegmentState> storage) : storage(storage) {}
    virtual bool contains(State s) const override {
        int n = storage.size();
        bool f = true;
        for (int i = 0; i < n; ++i)
            if (storage.at(i).contains(s) == false)
                f = false;
        return f;
    }
};

struct ProbabilityTest {
private:
    State const E_min, E_max;
public:
    ProbabilityTest(State E_min, State E_max) : E_min(E_min) , E_max(E_max) {}
    float test(Base& system, unsigned test_count, unsigned seed) const {
        std :: default_random_engine reng (seed);
        std :: uniform_int_distribution<int> dstr(E_min, E_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (system.contains(dstr(reng)))
                ++good;
        return static_cast<float>(good) / static_cast<float>(test_count);
    }
};

int main() {
    DiscreteState d = DiscreteState(0);
    SegmentState s = SegmentState(-100, 100);
    ProbabilityTest pt = ProbabilityTest(-1000, 1000);
    std::cout << pt.test(d, 20000, 1) << std::endl;
    std::cout << pt.test(s, 20000, 1) << std::endl;
    int seed = 1;
    for (int test_count = 1; test_count <= 1000; ++test_count) {
        ProbabilityTest pt1 = ProbabilityTest(-1000, 1000);
        std::cout << pt.test(s, test_count, seed) << std::endl;
        ++seed;
    }
    SegmentState s1 = SegmentState(-100, 25);
    SegmentState s2 = SegmentState(50, 100);
    std::vector<SegmentState> v = {s1, s2};
    Unite s12 = Unite(v);
    std::cout << std::endl;
    seed = 1;
    for (int test_count = 1; test_count <= 1000; ++test_count) {
        ProbabilityTest pt1 = ProbabilityTest(-1000, 1000);
        std::cout << pt.test(s12, test_count, seed) << std::endl;
        ++seed;
    }
    return 0;
};
