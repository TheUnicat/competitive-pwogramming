//
// Created by TheUnicat on 2024-05-26.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    int n_tests;
    std::cin >> n_tests;
    for (int n = 0; n < n_tests; n++) {
        int l;
        std::cin >> l;
        std::vector<int> test_case;
        for (int i = 0; i < l; i++) {
            int num;
            std::cin >> num;
            test_case.push_back(num);
        }

        auto max_it = std::max_element(test_case.begin(), test_case.end());
        int max_value = *max_it;

        while (true) {
            int current_count = 0;
            int operations = 0;
            bool begin = true;
            for (int i = 0; i < l; i++) {
                if (current_count == max_value && (test_case[i] != 0 || max_value == 0)) {
                    current_count = 0;
                    begin = true;
                }
                if (!begin) {
                    operations++;
                }

                current_count += test_case[i];
                begin = false;
            }

            if (current_count == max_value || current_count == 0) {
                std::cout << operations << std::endl;
                break;
            } else {
                max_value++;
            }
        }

    }
}