#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Mountain {
    int left;
    int right;
};

bool comp_mountains(const Mountain& a, const Mountain& b) {
    if (a.left == b.left) {
        return a.right > b.right;
    }
    return a.left < b.left;
}

int main() {
    int n;
    ifstream infile("mountains.in");
    infile >> n;
    vector<Mountain> mountains(n);
    for (int i = 0; i < n; i++) {
        int peak, size;
        infile >> peak >> size;
        mountains[i].left = peak - size;
        mountains[i].right = peak + size;
    }

    sort(mountains.begin(), mountains.end(), comp_mountains);

    int visible_count = 0;
    int rightmost_base = -1;

    for (const auto& mountain : mountains) {
        if (mountain.right > rightmost_base) {
            visible_count++;
            rightmost_base = mountain.right;
        }
    }

    ofstream outfile("mountains.out");
    outfile << visible_count;
    outfile.close();
}
