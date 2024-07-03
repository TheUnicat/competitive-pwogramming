//
// Created by TheUnicat on 2024-07-02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int solve(vector<int> test_case) {
    int max_points = 0;
    vector<int> prefix_max;
    vector<int> suffix_max;
    int size = test_case.size();
    for (int i = 0; i < size; i++) {
        prefix_max.push_back(test_case[i] + i + 1);
        suffix_max.push_back(test_case[i] - i - 1);
        //cout << prefix_max[i] << " " << suffix_max[i] << endl;
    }



    for (int i = 1; i < size - 1; i++) {
        int left = *max_element(suffix_max.begin(), suffix_max.begin() + i);
        int right = *max_element(prefix_max.begin() + i + 1, prefix_max.end());
       // cout << left << endl << right << endl << endl;
        int points = left + test_case[i] + right;
        if (points > max_points) {
            max_points = points;
        }
    }
    cout << endl;
    return max_points;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        vector<int> test_case(len);
        for (int j = 0; j < len; j++) {
            int num;
            cin >> num;
            test_case[j] = num;
        }
        cout << solve(test_case) << endl;
    }
}
