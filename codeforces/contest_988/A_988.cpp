//
// Created by TheUnicat on 2024-11-10.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        vector<int> numbers(a);
        map<int, int> count;
        for (int j = 0; j < a; j++) cin >> numbers[j];
        for (int num : numbers) count[num]++;
        int score = 0;
        while (true) {
            bool found = false;
            for (int j = 0; j < a; j++) {
                while (count[numbers[j]] >= 2) {
                    count[numbers[j]] -= 2;
                    score++;
                    found = true;
                }
            }
            if (!found) break;
        }

        cout << score << endl;
    }
}