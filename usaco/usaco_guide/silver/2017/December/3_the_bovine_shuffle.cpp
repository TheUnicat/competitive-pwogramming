//
// Created by TheUnicat on 2024-08-05.
//

#include <fstream>
#include <vector>
using namespace std;

int n;
vector<int> next_position;
vector<int> visits;
vector<bool> visited_now;

void dfs(int start) {
    if (visits[start] > 0 && !visited_now[start]) return;
    visits[start]++;
    visited_now[start] = true;
    if (visits[start] == 3) return;
    dfs(next_position[start]);
}

int main() {
    ifstream infile("shuffle.in");
    infile >> n;
    next_position.resize(n);
    visits.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int num;
        infile >> num;
        next_position[i] = num - 1;
    }
    infile.close();
    for (int i = 0; i < n; i++) {
        if (visits[i] == 0) {
            visited_now.clear();
            visited_now.resize(n, false);
            dfs(i);
        }
    }

    int occupied = 0;
    for (int i = 0; i < n; i++) if (visits[i] > 1) occupied++;

    ofstream outfile("shuffle.out");
    outfile << occupied;
    outfile.close();
}