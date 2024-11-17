//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        map<int, int> nums;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            nums[num]++;
        }

        int size = k - 2;
        for (int j = 1; j <= sqrt(size); j++) {
            int other =  size / j;
            if (other * j != size) continue;
            if (other != j) {
                if (nums[other] > 0 && nums[j] > 0) {
                    cout << other << " " << j << endl;
                    break;
                }
            }
            else if (nums[other] > 1) {
                cout << other << " " << j << endl;
                break;
            }
        }
    }
}