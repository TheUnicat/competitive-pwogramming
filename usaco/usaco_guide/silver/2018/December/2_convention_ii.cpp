//
// Created by TheUnicat on 2024-07-26.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int n;

int main() {
    vector<pair<pair<int, int>, int> >  cows;
    priority_queue<pair<int, pair<int, int> > > lineup;

    int current_time = 0;
    int max_wait = 0;
    ifstream infile("convention2.in");
    infile >> n;
    for (int i = 0; i < n; i++) {
        int arrival, time;
        infile >> arrival >> time;
        cows.push_back(make_pair(make_pair(arrival, time), n - i));
    }
    infile.close();

    sort(cows.begin(), cows.end());
    auto current_cow = cows.begin();

    while (true) {
        if (lineup.empty()) {
            if (current_cow == cows.end()) break;
            lineup.push(make_pair((*current_cow).second, (*current_cow).first));
            current_time = (*current_cow).first.first;
            current_cow++;
            while (current_cow != cows.end()) {
                if ((*current_cow).first.first == current_time) {
                    lineup.push(make_pair((*current_cow).second, (*current_cow).first));
                    current_cow++;
                }
                else break;
            }
        }

        auto cow = lineup.top();
        int waiting_time = current_time - cow.second.first;
        if (waiting_time > max_wait) max_wait = waiting_time;

        current_time += cow.second.second;
        lineup.pop();

        while (current_cow != cows.end()) {
            if ((*current_cow).first.first < current_time) {
                lineup.push(make_pair((*current_cow).second, (*current_cow).first));
                current_cow++;
            }
            else break;
        }
    }

    ofstream outfile("convention2.out");
    outfile << max_wait;
    outfile.close();
}