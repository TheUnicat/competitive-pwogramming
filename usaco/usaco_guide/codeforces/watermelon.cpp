//
// Created by TheUnicat on 2024-05-12.
//

#include <iostream>
#include <string>

int main() {
    int number;
    std::cin >> number;

    if ((number - 2) % 2 == 0 && number > 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}