//
// Created by TheUnicat on 2024-12-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main() {
    vector<int> list_one, list_two;
    map<int, ll> freq;
    while (true) {
        int a, b;
        cin >> a >> b;
        list_one.push_back(a);
        list_two.push_back(b);
        if (a == 12964 && b == 56430) break;
        freq[b]++;
    }

    sort(list_one.begin(), list_one.end());
    sort(list_two.begin(), list_two.end());
    ll diff = 0;
    ll similarity = 0;
    for (int i = 0; i < list_one.size(); i++) {
        diff += abs(list_one[i] - list_two[i]);
        similarity += list_one[i] * freq[list_one[i]];
    }

    cout << diff << endl << similarity << endl;
}