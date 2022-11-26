//
//  C.cpp
//  
//
//  Created by Elina Mukhamedova on 26.11.2022.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <map>

int max_element(std::vector<int>& v) {
    int max_ans = v[0];
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it > max_ans)
            max_ans = *it;
    }
    return max_ans;
}

int min_element(std::vector<int>& v) {
    int min_ans = v[0];
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it < min_ans)
            min_ans = *it;
    }
    return min_ans;
}

//std::vector<int> more_than_k_times(std::vector<int> vector, k) {
//    std::vector<int> dist;
//    int max_element = max_element(vector);
//    for (int i = 1; i <= max_element; ++i)
//        dist.push_back(0);
//    for (auto it = vector.begin(); it != vector.end(); it++) {
//        dist[*it] ++;
//    }
//}

int main() {
    std::vector<int> nums;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    map <int, int> dist;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        
    }
    return 0;
}
