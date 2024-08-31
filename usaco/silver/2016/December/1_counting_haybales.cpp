//
// Created by TheUnicat on 2024-07-29.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;

int main() {
    ifstream infile("haybales.in");
    ofstream outfile("haybales.out");
    infile >> n >> q;
    vector<int> haybales(n);
    for (int i = 0; i < n; i++) infile >> haybales[i];
    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < q; i++) {
        int l, r;
        infile >> l >> r;
        outfile << upper_bound(haybales.begin(), haybales.end(), r) - lower_bound(haybales.begin(), haybales.end(), l) << endl;
    }
    infile.close();
    outfile.close();
}