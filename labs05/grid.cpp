//
//  grid.cpp
//  
//
//  Created by Elina Mukhamedova on 03.12.2022.
//

#include <iostream>

template<class T>
static void destructArray(T* arr, size_t len) noexcept {
    for (size_t i = len; i > 0; i--) {
        arr[i - 1].~T();
    }
}

template <typename T, unsigned dim>
struct Grid final {
    using value_type = T;
    using size_type = unsigned;

    Grid(const T& val): Grid(1, 1, val) {
            static_assert(dim == 2);
        }
    
    template<class... Args>
    Grid(size_type x, Args... args): data(static_cast<Grid<T, dim - 1>*>(operator new(sizeof(Grid<T, dim - 1>) * x))),
                                    sz(x) {
        size_type done = 0;
        try {
            for (; done < sz; done++) {
                new(data + done) Grid<T, dim - 1>(args...);
            }
        } catch (...) {
            destructArray(data, done);
            throw;
        }
    }

    Grid(const Grid<T, dim> &other):
            data(static_cast<Grid<T, dim - 1>*>(operator new(sizeof(Grid<T, dim - 1>) * other.sz))),
            sz(other.sz) {
        size_type done = 0;
        try {
            for (; done < sz; done++) {
                new(data + done) Grid<T, dim - 1>(other[done]);
            }
        } catch (...) {
            destructArray(data, done);
            throw;
        }
    }

    Grid<T, dim>& operator=(const Grid<T, dim>& other) {
        if (this == &other) {
            return *this;
        }
        auto gridCopy = other;
        this->swap(gridCopy);
        return *this;
    }

    ~Grid() {
        destructArray(data, sz);
        operator delete(data);
    }

    void swap(Grid<T, dim> &other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
    }

    template<class... Args>
    T operator ()(size_type x, Args... rst) const {
    }

    template<class... Args>
    T& operator ()(size_type x, Args... rst) {
        return data[x](rst...);
    }

    Grid<T, dim - 1> operator[](size_type x) const {
        return data[x];
    }

    Grid<T, dim - 1>& operator[](size_type x) {
        return data[x];
    }

    template<size_type d>
    size_type get_size() const {
        if constexpr(d == 1) {
            return sz;
        } else {
            return data[0].template get_size<d - 1>();
        }
    }

private :
    Grid<T, dim - 1>* data;
    size_type sz;

};

template <typename T>
struct Grid<T, 1> final {
    using value_type = T;
    using size_type = unsigned;

    Grid(size_type x): data(static_cast<T*>(operator new(sizeof(T) * x))), sz(x) {
        size_type done = 0;
        try {
            for (; done < sz; done++) {
                new(data + done) T();
            }
        } catch (...) {
            destructArray(data, done);
            throw;
        }
    }

    Grid(size_type x, const T& val): data(static_cast<T*>(operator new(sizeof(T) * x))), sz(x) {
        size_type done = 0;
        try {
            for (; done < sz; done++) {
                new(data + done) T(val);
            }
        } catch (...) {
            destructArray(data, done);
            throw;
        }
    }

    Grid(const Grid<T, 1> &other): data(static_cast<T*>(operator new(sizeof(T) * other.sz))), sz(other.sz) {
        size_type done = 0;
        try {
            for (; done < sz; done++) {
                new(data + done) T(other[done]);
            }
        } catch (...) {
            destructArray(data, done);
            throw;
        }
    }

    Grid<T, 1>& operator=(const Grid<T, 1>& other) {
        if (this == &other) {
            return *this;
        }
        auto gridCopy = other;
        this->swap(gridCopy);
        return *this;
    }

    ~Grid() {
        destructArray(data, sz);
        operator delete(data);
    }

    void swap(Grid<T, 1> &other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
    }

    T operator ()(size_type x) const {
        return data[x];
    }

    T& operator ()(size_type x) {
        return data[x];
    }

    T operator[](size_type x) const {
        return data[x];
    }

    T& operator[](size_type x) {
        return data[x];
    }

    template<size_type d>
    size_type get_size() const {
        static_assert(d == 1, "wrong dimension");
        return sz;
    }

private :
    T* data;
    size_type sz;
};

