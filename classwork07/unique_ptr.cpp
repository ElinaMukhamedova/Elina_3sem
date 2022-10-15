//
//  unique_ptr.cpp
//  
//
//  Created by Elina Mukhamedova on 15.10.2022.
//

#include <iostream>
#include <memory>

template <typename T>
class unique_ptr {
private:
    T* ptr = nullptr;
public:
    explicit unique_ptr() {}
    
    explicit unique_ptr(T* ptr) : ptr(ptr) {}
    
    unique_ptr(const unique_ptr& other) = delete; // не позволяет использовать копирующий конструктор
    
    unique_ptr& operator=(const unique_ptr& other) = delete; // запрещает копирование через присваивание
    
    unique_ptr(unique_ptr&& other) : ptr(other.ptr) { // перемещающий конструктор
        other.ptr = nullptr; // уникальный указатель может быть только один на объект
    }
    
    unique_ptr& operator=(unique_ptr&& other) { // оператор перемещающего присваивания
        if (&other == this) {
            return *this;
        }
        delete[] ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    
    ~unique_ptr() {
        delete[] ptr;
    }
    
    T& operator*() const {
        return *ptr;
    }
    
    T* operator->() const {
        return ptr;
    }
};

int main() {
    return 0;
}
