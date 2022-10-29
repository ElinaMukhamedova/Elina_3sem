//
//  sort.cpp
//  
//
//  Created by Elina Mukhamedova on 08.10.2022.
//

#include <iostream>

template <typename T>
struct Comparator {
    virtual bool operator()(T const&, T const&) const = 0;
};
struct IntComparator final: Comparator<int> {
    bool operator() (int const& lha, int const& rha) const override {
        return lha <= rha;
    }
};

template <typename T>
void swap(T *a, T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}

template <typename T>
void printArray(T array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

template <typename T>
int partition(T array[], int low, int high) {
  T pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (Comparator.operator(array[j], pivot)) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

template<typename T>
void quickSort(T array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main() {
  int data[] = {13, 17, 7, 11, 21, 23, -5};
  int n = sizeof(data) / sizeof(data[0]);
  printArray(data, n);
  quickSort<int>(data, 0, n - 1);
  printArray<int>(data, n);
}

