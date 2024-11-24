//
// Created by TheUnicat on 2024-11-24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int n, rounds = 0;
vector<int> painting, compressed;
vector<int> freq;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    cin >> n;
    painting.resize(n);
    freq.resize(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> painting[i];
    if (painting[0] != 0) compressed.push_back(painting[0]);
    freq[painting[0]]++;
    for (int i = 1; i < n; i++) {
        if (painting[i] != painting[i - 1]) {
            if (painting[i] == 0) continue;
            compressed.push_back(painting[i]);
            freq[painting[i]]++;
        }
    }

    stack<int> curr;
    int single_colors = 0;
    for (auto color : compressed) {
        if (freq[color] == 1) {
            single_colors = 1;
            rounds = max(rounds, (int) curr.size() + single_colors);
            continue;
        }
        if (!curr.empty() && curr.top() == color && freq[color] == 2) {
            curr.pop();
            single_colors = 0;
        }
        else if (!curr.empty() && curr.top() == color && freq[color] > 2) freq[color]--;
        else {
            curr.push(color);
            rounds = max(rounds, (int) curr.size() + single_colors);
        }
    }
    if (!curr.empty()) {
        cout << -1 << endl;
    }
    else cout << rounds << endl;
}