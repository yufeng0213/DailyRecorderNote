//
// Created by MSI on 2024/11/27.
//

#include <iostream>
#include <string_view>

void print_substring(std::string_view sv, std::size_t pos, std::size_t len) {
    if (pos + len > sv.size()) {
        len = sv.size() - pos; // 防止越界
    }
    std::cout << sv.substr(pos, len) << std::endl;
}

int main() {
    std::string str = "Hello, C++17 and std::string_view!";
    std::string_view sv(str);

    std::cout << "Full string view: " << sv << std::endl;

    print_substring(sv, 7, 5); // 输出 "C++17"
    print_substring(sv, 27, 16); // 输出 "std::string_view"

    return 0;
}