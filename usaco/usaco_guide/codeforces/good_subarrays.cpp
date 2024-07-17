//
// Created by TheUnicat on 2024-07-14.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
using ll = long long;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll good_subarrays = 0;
        int length;
        map<int, ll> values;
        set<int> keys;
        cin >> length;
        string test;
        cin >> test;
        test = '0' + test;
        int sum = 0;
        for (int j = 0; j <= length; j++) {
            sum += test[j] - '0';
            values[sum - j]++;
            keys.insert(sum - j);
        }

        for (int key : keys) {
            ll permutations = values[key];
            good_subarrays += (permutations * (permutations - 1)) / 2;
        }

        cout << good_subarrays << endl;
    }
}