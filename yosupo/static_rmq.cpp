//
// Created by TheUnicat on 2025-01-14.
//

#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<vector<int>> rmq;

int floor_log(int num) {
    int ans = 0;
    while (num >= 2) {
        num /= 2;
        ans++;
    }
    return ans;
}

int query(int l, int r) {
    int power = floor_log(r - l);
    return min(rmq[power][l], rmq[power][r - (1 << power)]);
}

int main() {
    cin >> n >> q;
    rmq.resize(floor_log(n) + 1);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        rmq[0].push_back(num);
    }

    for (int i = 1; i <= floor_log(n); i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            rmq[i].push_back(min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]));
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}