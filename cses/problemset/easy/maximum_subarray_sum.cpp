//
// Created by TheUnicat on 2024-07-03.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<long long> numbers;
    vector<long long> min_prefix_sum;
    long long sum = 0;
    long long min_sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        sum += num;
        numbers.push_back(sum);
        min_prefix_sum.push_back(min_sum);
        if (sum < min_sum) {
            min_sum = sum;
        }
    }

    long long max_sum = numbers[n - 1];
    for (int i = 0; i < n; i++) {
        if (numbers[i] - min_prefix_sum[i] > max_sum) {
            max_sum = numbers[i] - min_prefix_sum[i];
        }
    }

    cout << max_sum;
}
