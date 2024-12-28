#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> cakes(n);
        ll total_size = 0;
        ll left_size = 0, right_size = 0;
        for (int j = 0; j < n; j++) {
            cin >> cakes[j];
            total_size += cakes[j];
            if (j < n / 2 - 1) left_size += cakes[j];
            if (j > n / 2) right_size += cakes[j];
        }
        ll ans = right_size;
        int right =  n / 2 + 1;
        for (int j = 0; j < n / 2 - 1; j++) {
            right_size -= cakes[right];
            right++;
            right_size += cakes[j];
            ans = max(ans, right_size);
        }

        cout << total_size - ans << " " << ans << endl;
    }
}


