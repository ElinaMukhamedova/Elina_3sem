//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 03.09.2022.
//

#include <iostream>


void swap(void** a, void** b) {
  void* tmp = *a;
  *a = *b;
  *b = tmp;
}


int main() {
  int a = 0, b = 2;
  void* ptr_a = &a;
  void* ptr_b = &b;
  swap(&ptr_a, &ptr_b);
  std::cout << (*reinterpret_cast<int*>(ptr_a)) << " " << (*reinterpret_cast<int*>(ptr_b)) << std::endl;
  return 0;
}
