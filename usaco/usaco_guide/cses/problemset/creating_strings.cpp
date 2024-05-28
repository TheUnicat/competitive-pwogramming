//
// Created by TheUnicat on 2024-05-27.
//

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

string orig_str;
vector<char> orig_vector;
vector<string> answers;
bool repeated_chars = false;

bool already_answered(string const &new_answer) {
    if (!repeated_chars) {
        return false;
    }
    if (find(answers.begin(), answers.end(), new_answer) == answers.end()) {
        return false;
    }

    return true;
}

void compute_answer(string const &current_str, std::vector<char> remaining_strs) {
    if (current_str.length() == orig_str.length()) {
        if (!already_answered(current_str)) {
            answers.push_back(current_str);
            return;
        }
    }
    for (int i = 0; i < remaining_strs.size(); i++) {
        vector<char> copy_vector = remaining_strs;
        copy_vector.erase(copy_vector.begin() + i);
        compute_answer(current_str + remaining_strs[i], copy_vector);
    }
}

int main() {
    cin >> orig_str;
    for (char character : orig_str) {
        orig_vector.push_back(character);
    }
    sort(orig_vector.begin(), orig_vector.end());
    for (int i = 0; i < orig_vector.size() - 1; i++) {
        if (orig_vector[i] == orig_vector[i + 1]) {
            repeated_chars = true;
        }
    }
    compute_answer("", orig_vector);
    std::cout << answers.size() << std::endl;
    for (string answer : answers) {
        std::cout << answer << std::endl;
    }
}