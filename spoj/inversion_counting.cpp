//
// Created by TheUnicat on 2024-12-07.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t, n;
vector<int> nums;
vector<int> segtree;

int query(int l, int r) {
    int sum = 0;
    l += 1e7, r += 1e7;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += segtree[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += segtree[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return sum;
}

void visit(int pos) {
    pos += 1e7;
    segtree[pos] = 1;
    pos /= 2;
    while (pos > 0) {
        segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
        pos /= 2;
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n_inversions = 0;
        nums.clear();
        segtree.clear();
        cin >> n;
        nums.resize(n);
        segtree.resize(2 * 1e7, 0);
        for (int j = 0; j < n; j++) cin >> nums[j];

        for (int j = 0; j < n; j++) {
            n_inversions += query(nums[j] - 1, 1e7);
            visit(nums[j] - 1);
        }

        cout << n_inversions << endl;
    }
}