//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 18.11.2022.
//

#include <iostream>
int main(){
    int n;
    std::cin >> n;
    unsigned long long int a[100] = {0};
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    for (int i = 4; i <= n; ++i)
        a[i] = a[i - 3] + a[i - 1];
    std::cout << a[n] << "\n";
    //for (int i = 1; i <= n; ++i)
    //    std::cout << a[i] << " ";
    return 0;
}
