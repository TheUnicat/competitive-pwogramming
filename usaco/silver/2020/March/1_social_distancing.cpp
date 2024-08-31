//
// Created by TheUnicat on 2024-07-29.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;

bool distance_valid(int distance, const vector<pair<ll, ll> > &grass) {
    ll current_point = grass[0].first;
    ll current_grass_index = 0;

    for (int i = 0; i < n - 1; i++) {
        current_point += distance;
        if (current_point > grass[current_grass_index].second) {
            while (true) {
                current_grass_index++;
                if (current_grass_index == m) return false;
                current_point = max(current_point, grass[current_grass_index].first);
                if (current_point <= grass[current_grass_index].second) break;
            }
        }
    }

    return true;
}

int main() {
    ifstream infile("socdist.in");
    infile >> n >> m;
    vector<pair<ll, ll> > grass_patches(m);
    for (int i = 0; i < m; i++) infile >> grass_patches[i].first >> grass_patches[i].second;
    infile.close();
    sort(grass_patches.begin(), grass_patches.end());
    distance_valid(2, grass_patches);

    ll min_bound = 1;
    ll max_bound = (grass_patches[m - 1].second - grass_patches[0].first) / (n - 1);

    int max_solution = 1;
    int last_mid = -1;
    while (max_bound >= min_bound) {
        int mid = min_bound + (max_bound - min_bound) / 2;
        if (mid == last_mid) break;
        last_mid = mid;
        if (distance_valid(mid, grass_patches)) {
            max_solution = mid;
            min_bound = mid + 1;
        }
        else {
            max_bound = mid;
        }
    }

    ofstream outfile("socdist.out");
    outfile << max_solution;
    outfile.close();
}
