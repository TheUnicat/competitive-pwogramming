//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, q;
        cin >> l >> q;
        vector<map<char, int> > string_one(l + 1);
        vector<map<char, int> > string_two(l + 1);
        string one, two;
        cin >> one >> two;
        for (int j = 1; j <= l; j++) {
            string_one[j] = string_one[j - 1];
            string_one[j][one[j - 1]]++;
            string_two[j] = string_two[j - 1];
            string_two[j][two[j - 1]]++;
        }

        for (int j = 0; j < q; j++) {
            int left, right;
            cin >> left >> right;
            int diffs = 0;
            auto map_one_right = string_one[right];
            auto map_one_left = string_one[left - 1];
            auto map_two_right = string_two[right];
            auto map_two_left = string_two[left - 1];
            map<char, int> string_one_sums;
            map<char, int> string_two_sums;
            for (const auto& pair : map_one_right) {
                char key = pair.first;
                string_one_sums[key] = abs(map_one_right[key] - map_one_left[key]);
            }
            for (const auto& pair : map_two_right) {
                char key = pair.first;
                string_two_sums[key] = abs(map_two_right[key] - map_two_left[key]);
            }

            set<char> alphabet;

            for (const auto& pair : string_one_sums) {
                char key = pair.first;
                alphabet.insert(key);
            }

            for (const auto& pair : string_two_sums) {
                char key = pair.first;
                alphabet.insert(key);
            }

            for (const auto& character : alphabet) {
                diffs += abs(string_one_sums[character] - string_two_sums[character]);
            }

            cout << diffs / 2 << endl;
        }

        string_one.clear();
        string_two.clear();
    }
}
