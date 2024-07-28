//
// Created by TheUnicat on 2024-07-26.
//

#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, B;

int main() {
    ifstream infile("snowboots.in");
    ofstream outfile("snowboots.out");
    infile >> N >> B;
    vector<int> path(N);
    set<pair<int, int> > cached_min_depths;
    for (int i = 0; i < N; i++) infile >> path[i];
    for (int i = 0; i < B; i++) {
        int s, d;
        infile >> s >> d;
        auto it = cached_min_depths.lower_bound(make_pair(d, 0));
        if (it != cached_min_depths.end()) {
            if ((*it).first == d) {
                if (s >= (*it).second) {
                    outfile << 1 << endl;
                }
                else outfile << 0 << endl;
                continue;
            }
            else {
                if (it != cached_min_depths.begin()) {
                    it--;
                    if (s >= (*it).second) {
                        outfile << 1 << endl;
                        continue;
                    }
                }
            }
        }

        int point = 0;
        int min_depth = 0;
        while (point < N - 1) {
            if (point + d >= N - 1) break;
            auto min_next_step = min_element(path.begin() + point + 1, path.begin() + point + d + 1);
            auto next_index = distance(path.begin(), min_next_step);
            if (*min_next_step > min_depth) min_depth = *min_next_step;
            point = next_index;
        }
        cached_min_depths.insert(make_pair(d, min_depth));
        if (min_depth <= s) outfile << 1 << endl;
        else outfile << 0 << endl;
    }
}