//
// Created by TheUnicat on 2024-12-06.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> nums;
int n, q;

void update(int pos, int new_value) {
    pos += n;
    nums[pos] = new_value;
    pos /= 2;
    while (pos > 0) {
        nums[pos] = nums[2 * pos] + nums[2 * pos + 1];
        pos /= 2;
    }
}

ll query(int l, int r) {
    ll sum = 0;
    l += n, r += n;
    while (l <= r) {
        if (l % 2 == 1) {
            sum += nums[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += nums[r];
            r--;
        }
        l /= 2, r /= 2;
    }

    return sum;
}

int main() {
    cin >> n >> q;
    nums.resize(2 * n);
    for (int i = 0; i < n; i++) cin >> nums[i + n];
    for (int i = n - 1; i >= 1; i--) nums[i] = nums[2 * i] + nums[2 * i + 1];

    for (int i = 0; i < q; i++) {
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int pos, new_value;
            cin >> pos >> new_value;
            update(pos - 1, new_value);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1) << endl;
        }
    }
}