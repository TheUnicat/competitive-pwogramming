//
// Created by TheUnicat on 2024-06-28.
//

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> graph;
int n;

int main() {
    ifstream infile("planting.in");
    string line;
    getline(infile, line);
    n = stoi(line);
    for (int i = 0; i < n; i++) {
        graph.push_back(1);
    }

    for (int i = 0; i < n - 1; i++) {
        getline(infile, line);
        int a, b;
        istringstream iss(line);
        iss >> a >> b;
        graph[a]++;
        graph[b]++;
    }
    infile.close();

    ofstream outfile("planting.out");
    outfile << *max_element(graph.begin(), graph.end());
    outfile.close();
}