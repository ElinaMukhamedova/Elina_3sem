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
    
    unique_ptr(unique_ptr&& other) : ptr(other.ptr) {
        other.ptr = nullptr; // уникальный указатель может быть только один на объект
    }
    
    unique_ptr(const unique_ptr& other) = delete; // не позволяет использовать копирующий конструктор
    
    unique_ptr& operator=(const unique_ptr& other) = delete; // запрещает копирование через присваивание
    
    
    
    ~unique_ptr() {
        delete[] ptr;
    }
};

int main() {
    return 0;
}
