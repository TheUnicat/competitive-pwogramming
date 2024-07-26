//
// Created by TheUnicat on 2024-07-26.
//

#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, B;

int main() {
    ifstream infile("snowboots.in");
    ofstream outfile("snowboots.out");
    infile >> N >> B;
    vector<int> path(N);
    map<int, int> cached_min_depths;
    for (int i = 0; i < N; i++) infile >> path[i];
    for (int i = 0; i < B; i++) {
        int s, d;
        infile >> s >> d;
        auto it = cached_min_depths.find(d);
        if (it != cached_min_depths.end()) {
            if (s >= (*it).second) {
                outfile << 1 << endl;
            }
            else outfile << 0 << endl;
            continue;
        }
        else {
            int point = 0;
            int min_depth = 0;
            while (point < N - 1) {
                if (point + d >= N - 1) break;
                auto min_next_step = min_element(path.begin() + point + 1, path.begin() + point + d + 1);
                int next_index = (int) distance(path.begin(), min_next_step);
                if (*min_next_step > min_depth) min_depth = *min_next_step;
                point = next_index;
            }
            cached_min_depths[d] = min_depth;
            if (min_depth <= s) outfile << 1 << endl;
            else outfile << 0 << endl;
        }
    }
}