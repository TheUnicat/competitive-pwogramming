//
// Created by TheUnicat on 2024-10-13.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int customers = 0;
        int n, x;
        ll sum = 0;
        ll max_num = 0;
        cin >> n >> x;
        for (int j = 0; j < n; j++) {
            ll num;
            cin >> num;
            sum += num;
            max_num = max(max_num, num);
        }

        ll min_customers = sum / (ll) x;
        if (sum % (ll) x != 0) min_customers++;
        cout << max(max_num, min_customers) << endl;
    }
}
