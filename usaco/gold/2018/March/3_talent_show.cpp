//
// Created by TheUnicat on 2024-08-25.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, w;
vector<pair<int, int> > cows;
vector<int> max_talent;
vector<ll> original_talents;
ll max_weight = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second / a.first > b.second / b.first;
}


int main() {
    ifstream infile("talent.in");
    infile >> n >> w;
    max_talent.resize(w + 1, 0);
    original_talents.resize(w + 1, 0);
    for (int i = 0; i < n; i++) {
        int talent, weight;
        infile >> weight >> talent;
        cows.push_back(make_pair(weight, talent));
    }
    infile.close();
    sort(cows.begin(), cows.end(), cmp);

    for (auto cow : cows) {
        for (int i = w; i >= 0; i--) {
            if (i == 0 || max_talent[i] > 0) {
                if (i == w) {
                    if (1000 * cow.second / cow.first > max_talent[w]) {
                        ll original_talent = original_talents[w];
                        max_weight += cow.first;
                        max_talent[w] = (original_talent + cow.second * 1000) / max_weight;
                        original_talents[w] = original_talent + cow.second;
                    }
                }
                else if (i + cow.first > w) {
                    ll original_talent = original_talents[i];
                    if ((1000 * cow.second + original_talent) / (i + cow.first) > max_talent[w]) {
                        max_talent[w] = (1000 * cow.second + original_talent) / (i + cow.first);
                        max_weight = i + cow.first;
                        original_talents[w] = 1000 * cow.second + original_talent;
                    }
                }
                else {
                    ll original_talent = original_talents[i];
                    if ((original_talent + 1000 * cow.second) / (i + cow.first) > max_talent[i + cow.first]) {
                        max_talent[i + cow.first] = (original_talent + 1000 * cow.second) / (i + cow.first);
                        original_talents[i + cow.first] = original_talent + 1000 * cow.second;
                    }
                }
            }
        }
    }

    ofstream outfile("talent.out");
    outfile << max_talent[w];
    outfile.close();
}