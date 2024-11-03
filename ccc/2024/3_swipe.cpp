//
// Created by TheUnicat on 2024-11-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a, b;

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int a_pos = 0;
    int b_pos = 0;
    bool solvable = true;
    while (b_pos < n) {
        if (a_pos == n) {
            solvable = false;
            break;
        }
        if (b[b_pos] == a[a_pos]) b_pos++;
        else a_pos++;
    }

    if (solvable) cout << "YES";
    else cout << "NO";
    cout << endl;
    if (solvable) {
        vector<pair<int, int>> left_swipes;
        vector<pair<int, int>> right_swipes;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int orig_j = j;
            bool right_swipe = false, left_swipe = false;
            while (j < i && a[i] == b[j]) {
                left_swipe = true;
                j++;
            }
            if (left_swipe) left_swipes.emplace_back(orig_j, i);

            int right = -1;
            while (j < n && a[i] == b[j]) {
                right = j;
                j++;
                right_swipe = true;
            }

            if (right_swipe && i != right) right_swipes.emplace_back(i, right);
        }

        cout << left_swipes.size() + right_swipes.size() << endl;
        reverse(right_swipes.begin(), right_swipes.end());

        for (auto swipe : left_swipes) {
            cout << "L " << swipe.first << " " << swipe.second << endl;
        }

        for (auto swipe : right_swipes) {
            cout << "R " << swipe.first << " " << swipe.second << endl;
        }
    }
}
