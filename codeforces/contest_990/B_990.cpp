//
// Created by TheUnicat on 2024-12-02.
//

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int t, n;
string curr_case;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        set<pair<int, char>> freqs;
        map<char, int> freq;
        cin >> n >> curr_case;
        for (int j = 0; j < n; j++) {
            freq[curr_case[j]]++;
        }

        char most_freq, least_freq;
        for (int j = 0; j < n; j++) {
            if (freq[curr_case[j]] != 0) {
                freqs.emplace(freq[curr_case[j]], curr_case[j]);
                freq[curr_case[j]] = 0;
            }
        }

        least_freq = (*freqs.begin()).second;
        auto end_it = freqs.end();
        end_it--;
        most_freq = (*end_it).second;

        for (int j = 0; j < n; j++) {
            if (curr_case[j] == least_freq) {
                curr_case[j] = most_freq;
                break;
            }
        }

        cout << curr_case << endl;
    }
}