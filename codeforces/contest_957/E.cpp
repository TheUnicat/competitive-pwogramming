//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        int n_bad = 0;
        vector<pair<int, int> > bad_cases;
        cin >> x;
        for (int a = 1; a <= 10000; a++) {
            int a_times_x = a * x;
            for (int b = 1; b <= a; b++) {
                string x_string(n, to_string(x));
                int string_sum = stoi(x_string);
                if (string_sum == a * x - b) {
                    n_bad++;
                    bad_cases.push_back(make_pair(a, b));
                }
                else if (string_sum > a * x - b) {
                    break;
                }
            }
        }

        cout << n_bad << endl;
        for (auto bad_case : bad_cases) {
            cout << bad_case.first << " " << bad_case.second << endl;
        }
    }
}