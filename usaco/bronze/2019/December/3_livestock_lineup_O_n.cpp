//
// Created by TheUnicat on 2024-06-28.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>;
using namespace std;

int n;
string trash;
vector<vector<int> > graph(8);
vector<bool> selected(8, false);
map<string, int> cow_map;
vector<string> cows;
vector<string> final_list;


int main() {
    cows.push_back("Beatrice");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Bella");
    cows.push_back("Belinda");
    sort(cows.begin(), cows.end());
    for (int i = 0; i < 8; i++) {
        cow_map[cows[i]] = i;
    }

    ifstream infile("lineup.in");
    string line;
    getline(infile, line);
    n = stoi(line);
    for (int i = 0; i < n; i++) {
        string a, b;
        getline(infile, line);
        istringstream iss(line);
        iss >> a >> trash >> trash >> trash >> trash >> b;
        graph[cow_map[a]].push_back(cow_map[b]);
        graph[cow_map[b]].push_back(cow_map[a]);
    }

    for (int i = 0; i < 8; i++) {
        if (graph[i].size() < 2 && selected[i] == false) {
            if (graph[i].size() == 0) {
                selected[i] = true;
                final_list.push_back(cows[i]);
            }
            else {
                int last_node = -1;
                int current_node = i;

                while (true) {
                    selected[current_node] = true;
                    bool is_done = true;
                    final_list.push_back(cows[current_node]);
                    for (auto edge : graph[current_node]) {
                        if (edge == last_node || selected[edge] == true) {
                            continue;
                        }
                        else {
                            last_node = current_node;
                            current_node = edge;
                            is_done = false;
                        }
                    }
                    if (is_done) {
                        break;
                    }
                }
            }
        }
    }

    ofstream outfile("lineup.out");
    for (string cow : final_list) {
        outfile << cow << endl;
    }
}