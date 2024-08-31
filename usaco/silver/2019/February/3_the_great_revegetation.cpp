//
// Created by TheUnicat on 2024-08-01.
//

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
char type;
vector<vector<pair<int, bool> > > graph;
vector<int> searched;

bool dfs(int start, int c) {
    if (searched[start] != 0) return c == searched[start];
    searched[start] = c;

    for (pair<int, bool> connected : graph[start]) {
        int new_c = connected.second == false ? 3 - c : c;
        if (!dfs(connected.first, new_c)) return false;
    }

    return true;
}

int main() {
    ifstream infile("revegetate.in");
    infile >> n >> m;
    graph.resize(n, vector<pair<int, bool> >());
    searched.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int first, second;
        infile >> type >> first >> second;
        bool preference = type == 'D' ? false : true;
        graph[first - 1].push_back(make_pair(second - 1, preference));
        graph[second - 1].push_back(make_pair(first - 1, preference));
    }
    infile.close();

    int components = 0;
    auto it = searched.begin();
    while (it != searched.end()) {
        if (*it == 0) {
            if (!dfs(distance(searched.begin(), it), 1)) {
                ofstream outfile("revegetate.out");
                outfile << 0;
                outfile.close();
                return 0;
            }
            components++;
        }
        it++;
    }

    string answer = "1";
    for (int i = 0; i < components; i++) {
        answer += "0";
    }

    ofstream outfile("revegetate.out");
    outfile << answer;
    outfile.close();
}