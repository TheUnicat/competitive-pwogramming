//
// Created by TheUnicat on 2024-08-06.
//

#include <iostream>
#include <string>
using namespace std;

int t;
string one, two;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> one >> two;
        bool solvable = false;
        string answer_string = "";
        int curr_one = 0;

        for (int j = 0; j < two.length(); j++) {
            while (curr_one < one.length()) {
                if (one[curr_one] == two[j]) {
                    answer_string += one[curr_one];
                    if (j == two.length() - 1) {
                        solvable = true;
                    }
                    curr_one++;
                    break;
                }
                if (one[curr_one] == '?') {
                    //cout << "uwu" << two[j] << endl;
                    answer_string += two[j];
                    if (j == two.length() - 1) {
                        solvable = true;
                    }
                    curr_one++;
                    break;
                }
                answer_string += one[curr_one];
                curr_one++;
            }
        }

       // cout << curr_one << endl;
        if (solvable) {
            for (int j = curr_one; j < one.length(); j++) {
                if (one[j] != '?') answer_string += one[j];
                else answer_string += 'a';
            }
        }

        if (solvable) cout << "YES" << endl << answer_string;
        else cout << "NO";
        cout << endl;
    }
}
