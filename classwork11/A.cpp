//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 12.11.2022.
//

#include <iostream>
#include <vector>

int max_element(std::vector<int>& v) {
    int max_ans = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it > max_ans)
            max_ans = *it;
    }
    return max_ans;
}

int numRabbits(std::vector<int>& answers) {
    int min_num = 0;
    int max_ans = max_element(answers);
    std::vector<int> ans_dist;
    for (int i = 1; i <= max_ans + 1; ++i)
        ans_dist.push_back(0);
    for (auto it = answers.begin(); it != answers.end(); it++) {
        ans_dist[*it] ++;
    }
    //for (int i = 0; i <= max_ans; ++i)
    //    std::cout << ans_dist[i] << " ";
    //std::cout << std::endl;
    for (int i = 0; i <= max_ans; ++i) {
        min_num += (ans_dist[i] / (i + 1)) * (i + 1);
        if (ans_dist[i] % (i + 1) != 0)
            min_num += i + 1;
        //std::cout << min_num << "\n";
    }
    return min_num;
}

int main() {
    std::vector<int> answers;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        std::cin >> x;
        answers.push_back(x);
    }
    //for (auto it = answers.begin(); it != answers.end(); it++) {
    //    std::cout << *it << " ";
    //}
    //std::cout << max_element(answers) << "\n";
    std::cout << numRabbits(answers) << "\n";
    return 0;
}
