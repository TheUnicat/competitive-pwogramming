//
// Created by TheUnicat on 2024-06-09.
//
 
#include <algorithm>
#include <vector>
#include <iostream>
#define all(vec) vec.begin(), vec.end()
using namespace std;
 
vector<int> nums;
int n;
 
int calculate_instability(int index_one, int index_two) {
    int instability = 0;
    vector<int> copy_nums = nums;
    copy_nums.erase(copy_nums.begin() + max(index_one, index_two));
    copy_nums.erase(copy_nums.begin() + min(index_one, index_two));
    for (int i = 0; i < n - 2; i+=2) {
        instability += abs(copy_nums[i] - copy_nums[i + 1]);
    }
    return instability;
}
 
int main() {
    cin >> n;
    n *= 2;
    int num;
    int instability;
    int temp_instability;

    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
 
    sort(all(nums));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp_instability = calculate_instability(i, j);
            if (temp_instability < instability || (i == 0 && j == 1)) {
                instability = temp_instability;
            }
        }
    }

    cout << instability;
}