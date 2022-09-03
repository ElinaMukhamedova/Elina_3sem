//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 03.09.2022.
//

#include <iostream>


int compare_int(void* first, void* second) {
    return (reinterpret_cast<int*>(first)) - (reinterpret_cast<int*>(second));
}


int min(void arr[], int arr_size, int type_size, int (*compare)(void *, void *)) {
    void* ans = arr;
    void* ptr = arr;
    int k = 0;
    for (int i = 0; i < arr_size; i++) {
        if (compare(ptr, ans) < 0) {
            ans = ptr;
            k = i;
        }
        ptr += type_size;
    }
    return k;
}


int main() {
    int arr[5] = {5, 7, 4, 8, -1};
    std::cout << min(arr, 5, sizeof(arr[0]), compare_int);
    return 0;
}
