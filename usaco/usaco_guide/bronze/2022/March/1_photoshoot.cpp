//
// Created by TheUnicat on 2024-06-23.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    int swaps = 0;
    cin >> n;
    string cows;
    cin >> cows;

    string simplified = "";
    for (int i = 0; i < n; i+=2) {
        if (cows[i] == cows[i+1]) {
            continue;
        }
        else if (cows[i] == 'G') {
            simplified += "B";
        }
        else {
            simplified += "A";
        }
    }

    while (true) {
        while (true) {
            if (simplified[simplified.length() - 1] == 'A') {
                simplified = simplified.substr(0, simplified.length() - 1);
            }
            else {break;}
        }

        string compressed;
        for (int i = 1; i < simplified.length(); i++) {
            if (simplified[i] != simplified[i - 1]) {
                compressed += simplified[i];
            }
        }
        simplified = compressed;

        int best_index = 0;
        int n_A = 0;
        int n_B = 0;
        int max_B_minus_A = 0;
        for (int i = 0; i < simplified.length(); i++) {
            if (simplified[i] == 'A') {n_A++;} else {n_B++;}
            if (n_B - n_A > max_B_minus_A) {
                best_index = i;
                max_B_minus_A++;
            }
        }
        if (best_index > 0) {
            for (int i = 0; i < best_index + 1; i++) {
                simplified[best_index - i] == 'A' ? simplified[i] = 'B' : simplified[i] = 'A';
            }
            swaps++;
        } else {break;}
    }
    
    cout << simplified.length() + 1 << endl;
}
