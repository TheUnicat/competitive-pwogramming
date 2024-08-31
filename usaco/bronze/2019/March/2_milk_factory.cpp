//
// Created by TheUnicat on 2024-06-28.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> graph;
vector<bool> stations;

vector<int> search_station(int x) {
    vector<int> unvisited;
    int steps = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        visited[x] = true;
        x = graph[x];
        if (x == -1) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) { unvisited.push_back(i); }
    }
    return unvisited;
}


int main() {
    ifstream infile("factory.in");
    string line;
    getline(infile, line);
    n = stoi(line);
    for (int i = 0; i < n; i++) {
        graph.push_back(-1);
        stations.push_back(true);
    }
    for (int i = 0; i < n - 1; i++) {
        getline(infile, line);
        istringstream iss(line);
        int a, b;
        iss >> a >> b;
        graph[a - 1] = b - 1;
    }
    infile.close();

    for (int i = 0; i < n; i++) {
        vector<int> unvisited = search_station(i);
        for (int place: unvisited) {
            stations[place] = false;
        }
    }

    bool answer = false;
    for (int i = 0; i < n; i++) {
        if (stations[i] == true) {
            ofstream outfile("factory.out");
            outfile << i + 1;
            outfile.close();
            answer = true;
        }
    }
    if (!answer) {
        ofstream outfile("factory.out");
        outfile << -1;
        outfile.close();
    }
}