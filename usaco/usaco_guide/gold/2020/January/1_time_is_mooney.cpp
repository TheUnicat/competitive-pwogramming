//
// Created by TheUnicat on 2024-08-24.
//

#include <fstream>
#include <vector>
using namespace std;

int n, m, c;
vector<int> city_moonies;
vector<vector<int> > connections;
vector<vector<int> > max_by_time_and_pos(1002, vector<int>(2000, -1));

int main() {
    max_by_time_and_pos[0][0] = 0;
    ifstream infile("time.in");
    infile >> n >> m >> c;

    city_moonies.resize(n);
    connections.resize(n, vector<int>());

    for (int i = 0; i < n; i++) infile >> city_moonies[i];
    for (int i = 0; i < m; i++) {
        int start, end;
        infile >> start >> end;
        connections[start - 1].push_back(end - 1);
    }
    infile.close();

    int max_moonies = 0;
    for (int day = 0; day <= 1000; day++) {
        for (int pos = 0; pos < n; pos++) {
            if (max_by_time_and_pos[day][pos] == -1) continue;
            for (int connection : connections[pos]) {
                int new_moonies = max_by_time_and_pos[day][pos] + city_moonies[connection];
                int time_cost = c * (day + 1) * (day + 1);
                max_by_time_and_pos[day + 1][connection] = max(max_by_time_and_pos[day + 1][connection], new_moonies);
                if (connection == 0 && new_moonies - time_cost > max_moonies) max_moonies = new_moonies - time_cost;
            }
        }
    }

    ofstream outfile("time.out");
    outfile << max_moonies;
    outfile.close();
}

