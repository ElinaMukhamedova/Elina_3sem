//
//  D.cpp
//  
//
//  Created by Elina Mukhamedova on 03.09.2022.
//

#include <iostream>
#include <limits>
#include <string>
#include <typeinfo>


void info(void* x) {
    
}


int main() {
    std::cout << typeid(5).name() << std::endl;
    //std::cout << std::numeric_limits<typeid(5).name()>::min() << std::endl;
    return 0;
}
