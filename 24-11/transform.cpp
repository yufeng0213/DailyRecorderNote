//
// Created by MSI on 2024/11/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());

    std::transform(vec.begin(), vec.end(), result.begin(), [](int n){ return n * n; });

    for (int n : result) {
        std::cout << n << " ";
    }
    return 0;
}