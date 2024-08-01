//
// Created by TheUnicat on 2024-08-01.
//

#include <fstream>
#include <vector>
using namespace std;

vector<vector<int> > course;
vector<vector<bool> > waypoints;
vector<vector<bool> > visited;
int waypoints_reached = 0;
int n_waypoints = 0;

int m, n;

void floodfill(int x, int y, int max_diff, int prev_val) {
    if (x == -1 || x == m || y == -1 || y == n) return;
    if (visited[x][y]) return;
    int value = course[x][y];
    if (abs(value - prev_val) > max_diff) return;

    visited[x][y] = true;
    if (waypoints[x][y]) waypoints_reached++;

    floodfill(x + 1, y, max_diff, value);
    floodfill(x - 1, y, max_diff, value);
    floodfill(x, y + 1, max_diff, value);
    floodfill(x, y - 1, max_diff, value);
}

int main() {
    ifstream infile("ccski.in");
    infile >> m >> n;
    course.resize(m, vector<int>(n));
    waypoints.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            infile >> course[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int waypoint;
            infile >> waypoint;
            if (waypoint) {
                waypoints[i][j] = true;
                n_waypoints++;
            }
        }
    }

    infile.close();

    int min_bound = 0;
    int max_bound = 1000000000;
    int min_elevation = -1;

    while (max_bound >= min_bound) {
        int mid = min_bound + (max_bound - min_bound) / 2;
        waypoints_reached = 0;
        visited.clear();
        visited.resize(m, vector<bool>(n, false));
        floodfill(0, 0, mid, course[0][0]);

        if (waypoints_reached == n_waypoints) {
            min_elevation = mid;
            max_bound = mid - 1;
        }
        else min_bound = mid + 1;
    }

    ofstream outfile("ccski.out");
    outfile << min_elevation;
    outfile.close();
}