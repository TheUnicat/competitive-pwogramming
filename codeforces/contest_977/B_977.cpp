//
// Created by TheUnicat on 2024-10-05.
//

#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, x;
        cin >> n >> x;
        map<ll, int> nums;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            nums[num]++;
        }

        ll curr_val = 0;
        while (true) {
            if (nums[curr_val] == 0) break;
            if (nums[curr_val] > 1) nums[curr_val + x] += nums[curr_val] - 1;
            curr_val++;
        }

        cout << curr_val << endl;
    }
}