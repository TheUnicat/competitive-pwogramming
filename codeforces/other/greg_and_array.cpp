//
// Created by TheUnicat on 2024-07-11.
//

#include <iostream>
#include <vector>
using namespace std;

vector<long long> og_array;

int n, m, k;


int main() {
    cin >> n >> m >> k;
    vector<long long> array_prefix_sum(n, 0);
    vector<int> operations_prefix_sum(m, 0);
    vector<vector<int> > operations(m);
    vector<pair<int, int> > queries(k);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        og_array.push_back(num);
    }
    for (int i = 0; i < m; i++) {
        vector<int> operation(3);
        cin >> operation[0] >> operation[1] >> operation[2];
        operations[i] = operation;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        operations_prefix_sum[y - 1] += 1;
        if (x != 1) operations_prefix_sum[x - 2] -= 1;
    }

    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += operations_prefix_sum[m - i];
        vector<int> operation = operations[m - i];
        int l = operation[0];
        int r = operation[1];
        int d = operation[2];
        array_prefix_sum[r - 1] += d * sum;
        if (l != 1) array_prefix_sum[l - 2] -= d * sum;
    }

    long long sum_two = 0;
    for (int i = 1; i <= n; i++) {
        sum_two += array_prefix_sum[n - i];
        og_array[n - i] += sum_two;
    }

    for (long long num : og_array) {
        cout << num << " ";
    }
}