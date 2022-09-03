//
//  A1.cpp
//  
//
//  Created by Elina Mukhamedova on 03.09.2022.
//

#include <iostream>


void swap(void arr[], int i, int j, std::size_t type_size) {
    void* tmp = malloc(type_size);
    std::memcpy (tmp, arr + type_size * i, type_size);
    std::memcpy (arr + type_size * i, arr + type_size * j, type_size);
    std::memcpy (arr + type_size * j, tmp, type_size);
}


int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    swap(arr, 2, 4, sizeof(arr[0]));
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << "/t";
    return 0;
}
