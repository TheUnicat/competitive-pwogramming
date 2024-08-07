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
                string x_string = "";
                string x_char = to_string(x);
                for (int o = 0; o < a - b; o++) x_string += x_char;
                cout << x_string << "hi";
                if (x_string == to_string(a * x - b)) {
                    n_bad++;
                    bad_cases.push_back(make_pair(a, b));
                }
                else if (x_string.size() > to_string(a * x - b).size()) {
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