//
// Created by TheUnicat on 2024-07-07.
//

#include <iostream>
using namespace std;

int n;
int input;

void solve_case(int test_case) {
    for (int i = 0; i < test_case; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        solve_case(input);
    }
}