//
// Created by TheUnicat on 2024-06-05.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <string>
using namespace std;

vector<pair<int, int> > rectangles;

bool can_square(bitset<8> permutation) {
    vector<int> y_values;
    vector<int> x_values;
    vector<vector<char> > final_answer;
    int x_sum = 0;
    int y_sum = 0;

    for (int i = 0; i < 3; i++) {
        if (permutation[i] == 1) {
            x_sum += rectangles[i].first;
            x_values.push_back(rectangles[i].first);
            y_sum += rectangles[i].second;
            y_values.push_back(rectangles[i].second);
        }
        else {
            x_sum += rectangles[i].second;
            x_values.push_back(rectangles[i].second);
            y_sum += rectangles[i].first;
            y_values.push_back(rectangles[i].first);
        }
    }


    if (x_values[0] == x_values[1] && x_values[1] == x_values[2]
        && ((y_values[0] + y_values[1] + y_values[2]) == x_values[0]))
        {
        for (int i = 0; i < x_values[0]; i++) {
            if (i < y_values[0]) {
                vector<char> A(x_values[0], 'A');
                final_answer.push_back(A);
            }
            else if (i < y_values[0] + y_values[1]) {
                vector<char> B(x_values[0], 'B');
                final_answer.push_back(B);
            }
            else {
                vector<char> C(x_values[0], 'C');
                final_answer.push_back(C);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (x_values[i] == (x_values[0] + x_values[1] + x_values[2] - x_values[i])) {
            int y_value = -1;
            bool viable = true;
            for (int j = 0; j < 3; j++) {
                if (j == i) {
                    continue;
                }

                if (y_value == -1) {
                    y_value = y_values[j];
                    continue;
                }


                if (y_values[j] != y_value) {
                    viable = false;
                    break;
                }
            }

            if (!viable) {
                continue;
            }

            if (y_values[i] + y_value == x_values[i]) {
                for (int j = 0; j < y_values[i]; j++) {
                    vector<char> I(x_values[i], (i == 0 ? 'A' : (i == 1 ? 'B' : 'C')));
                    final_answer.push_back(I);
                }

                vector<char> line;
                for (int k = 0; k < 3; k++) {
                    if (k != i) {
                        for (int m = 0; m < x_values[k]; m++) {
                            line.push_back(k == 0 ? 'A' : (k == 1 ? 'B' : 'C'));
                        }
                    }
                }

                for (int j = 0; j < y_value; j++) {
                    final_answer.push_back(line);
                }
            }
        }
    }

    if (final_answer.size() > 0) {
        cout << final_answer.size() << endl;
        for (vector<char> line : final_answer) {
            for (char character : line) {
                cout << character;
            }
            cout << endl;
        }
        return true;
    }

    return false;

}

int main() {
    for (int i = 0; i < 3; i++) {
        pair<int, int> rectangle;
        cin >> rectangle.first;
        cin >> rectangle.second;
        rectangles.push_back(rectangle);
    }



    for (int i = 1; i <= 8; i++) {
        bitset<8> bitmask(i);
        if (can_square(bitmask)) {
            return 0;
        }
    }


    cout << "-1";
}