//
// Created by TheUnicat on 2024-12-06.
//

#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> nums;
// 0 1 2 1 2 4 1 3 3 2 4 5 1 1 5 3

void update(int pos, int new_value) {
    pos += n;
    nums[pos] = new_value;
    pos /= 2;
    while (pos > 0) {
        nums[pos] = min(nums[2 * pos], nums[2 * pos + 1]);
        pos /= 2;
    }
}

int query(int a, int b) {
    int curr_min = 2e9;
    a += n;
    b += n;

    while (a <= b) {
        if (a % 2 == 1) {
            curr_min = min(curr_min, nums[a]);
            a++;
        }
        if (b % 2 == 0) {
            curr_min = min(curr_min, nums[b]);
            b--;
        }

        a /= 2;
        b /= 2;
    }

    return curr_min;
}

int main() {
    cin >> n >> q;
    nums.resize(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> nums[n + i];
    }
    for (int i = n - 1; i >= 1; i--) {
        nums[i] = min(nums[2 * i], nums[2 * i + 1]);
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, new_value;
            cin >> pos >> new_value;
            update(pos - 1, new_value);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b - 1) << endl;
        }
    }
}

