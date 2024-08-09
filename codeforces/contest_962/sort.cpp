//
// Created by TheUnicat on 2024-07-26.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, q;
        cin >> l >> q;
        vector<vector<int> > string_one(l + 1, vector<int>(26, 0));
        vector<vector<int> > string_two(l + 1, vector<int>(26, 0));
        string one, two;
        cin >> one >> two;
        for (int j = 1; j <= l; j++) {
            string_one[j] = string_one[j - 1];
            string_one[j][one[j - 1] - 'a']++;
            string_two[j] = string_two[j - 1];
            string_two[j][two[j - 1] - 'a']++;
        }

        for (int j = 0; j < q; j++) {
            int left, right;
            cin >> left >> right;
            int diffs = 0;
            auto map_one_right = string_one[right];
            auto map_one_left = string_one[left - 1];
            auto map_two_right = string_two[right];
            auto map_two_left = string_two[left - 1];
            vector<int> string_one_sums(26, 0);
            vector<int> string_two_sums(26, 0);
            for (int k = 0; k < 26; k++) {
                string_one_sums[k] = abs(map_one_right[k] - map_one_left[k]);
            }
            for (int k = 0; k < 26; k++) {
                string_two_sums[k] = abs(map_two_right[k] - map_two_left[k]);
            }


            for (int k = 0; k < 26; k++) {
                diffs += abs(string_one_sums[k] - string_two_sums[k]);
            }

            cout << diffs / 2 << endl;
        }

        string_one.clear();
        string_two.clear();
    }
}
