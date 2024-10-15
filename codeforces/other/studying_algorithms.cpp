//
// Created by TheUnicat on 2024-07-28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int time, n;
    int answer = 0;

    cin >> n >> time;
    vector<int> algorithms(n);
    for (int i = 0; i < n; i++) cin >> algorithms[i];
    sort(algorithms.begin(), algorithms.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += algorithms[i];
        if (sum > time) break;
        answer++;
    }

    cout << answer << endl;
}