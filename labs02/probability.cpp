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
    virtual bool contains() = 0;
}

class DiscreteState : Base{
private:
    State const s0;
public:
    DiscreteState(State s0) : s0(s0) {}
    virtual bool contains(State s) const override{
        return s == s0;
    }
};

class SegmentState : Base{
private:
    State const begin_s0, end_s0;
public:
    SegmentState(State begin_s0, State end_s0) : begin_s0(begin_s0), end_s0(end_s0) {}
    virtual bool contains(State s) const override {
        return begin_s0 <= s and end_s0 >= s;
    }
};

class Unite : Base {
private:
    std::vector<SegmentState> storage;
public:
    virtual bool contains(State s) const override {
        int n = storage.size();
        bool f = false;
        for (int i = 0; i < n; ++i)
            if (storage.at(i).contains(s))
                f = true;
        return f;
    }
};

class Intersect : Base {
private:
    std :: vector<SegmentState> storage;
public:
    virtual bool contains(State s) const override {
        int n = storage.size();
        bool f = true;
        for (int i = 0; i < n; ++i)
            if (storage.at(i).contains(s) == false)
                f = false;
        return f;
    }
};

class ProbabilityTest {
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
    
    return 0;
};
