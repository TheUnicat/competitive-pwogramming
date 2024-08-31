//
// Created by TheUnicat on 2024-08-25.
//

#include <fstream>
#include <vector>
using namespace std;

int t, a, b;
vector<bool> fullness(5000001, false);

int main() {
    fullness[0] = true;
    ifstream infile("feast.in");
    infile >> t >> a >> b;
    infile.close();

    for (int i = 0; i <= t; i++) {
        if (fullness[i]) {
            if (i + a <= t) fullness[i + a] = true;
            if (i + b <= t) fullness[i + b] = true;
        }
    }

    for (int i = 0; i <= t; i++) {
        if (fullness[i]) {
            fullness[i / 2] = true;
        }
    }

    for (int i = 0; i <= t; i++) {
        if (fullness[i]) {
            if (i + a <= t) fullness[i + a] = true;
            if (i + b <= t) fullness[i + b] = true;
        }
    }

    for (int i = t; i >= 0; i--) {
        if (fullness[i]) {
            ofstream outfile("feast.out");
            outfile << i;
            outfile.close();
            return 0;
        }
    }
}