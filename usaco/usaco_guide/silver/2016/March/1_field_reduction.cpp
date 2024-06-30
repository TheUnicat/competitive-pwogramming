//
// Created by TheUnicat on 2024-06-29.
//

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > cows;
vector<pair<int, int> > cows_reversed;

int main() {
    ifstream infile("reduce.in");
    string line;
    getline(infile, line);
    n = stoi(line);

    for (int i = 0; i < n; i++) {
        getline(infile, line);
        istringstream iss(line);
        int x, y;
        iss >> x >> y;
        cows.push_back(make_pair(x, y));
        cows_reversed.push_back(make_pair(y, x));
    }
    infile.close();

    sort(cows.begin(), cows.end());
    sort(cows_reversed.begin(), cows_reversed.end());

    int min_area = (cows[n - 1].first - cows[0].first) * (cows_reversed[n - 1].first - cows_reversed[0].first);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                int choices[3] = {i, j, k};
                int x_front = 0;
                int x_back = 0;
                int y_front = 0;
                int y_back = 0;

                for (int num : choices) {
                    if (num == 0) {x_front++;}
                    else if (num == 1) {x_back++;}
                    else if (num == 2) {y_front++;}
                    else if (num == 3) {y_back++;}
                }

                auto copy_cows = cows;
                auto copy_reversed_cows = cows_reversed;

                vector<pair<int, int> > sold_cows;

                for (int m = 0; m < x_front; m++) {
                    sold_cows.push_back(cows[m]);
                }
                for (int m = 0; m < x_back; m++) {
                    sold_cows.push_back(cows[n - 1 - m]);
                }
                for (int m = 0; m < y_front; m++) {
                    sold_cows.push_back(make_pair(cows_reversed[m].second, cows_reversed[m].first));
                }
                for (int m = 0; m < y_back; m++) {
                    sold_cows.push_back(make_pair(cows_reversed[n - 1 - m].second, cows_reversed[n - 1 - m].first));
                }


                for (auto cow : sold_cows) {
                    auto it = find(copy_cows.begin(), copy_cows.end(), cow);
                    if (it != copy_cows.end()) {
                        copy_cows.erase(it);
                    }

                    auto reversed_cow = std::make_pair(cow.second, cow.first);
                    auto reversed_it = find(copy_reversed_cows.begin(), copy_reversed_cows.end(), reversed_cow);
                    if (reversed_it != copy_reversed_cows.end()) {
                        copy_reversed_cows.erase(reversed_it);
                    }
                }
                int new_area = (copy_cows[copy_cows.size() - 1].first - copy_cows[0].first) * (copy_reversed_cows[copy_reversed_cows.size() - 1].first - copy_reversed_cows[0].first);

                if (new_area < min_area) {
                    min_area = new_area;
                }
            }
        }
    }

    ofstream outfile("reduce.out");
    outfile << min_area;
    outfile.close();
}
