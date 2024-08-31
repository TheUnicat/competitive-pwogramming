//
// Created by TheUnicat on 2024-05-27.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution_count = 0;


bool check_legality(vector<pair<int, int> > queens) {
    for (long i = 0; i < queens.size(); i++) {
        for (long j = i + 1; j < queens.size(); j++) {
            if (queens[i].first == queens[j].first || queens[i].second == queens[j].second || abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second)) {
                return false;
            }
        }
    }
    return true;
}


void find_solutions(vector<pair<int, int> > queens, vector<string> const &chessboard) {
    if (check_legality(queens)) {
        if (queens.size() == 8) {
            solution_count++;
            return;
        }

        for (int i = 0; i < 8; i++) {
            if (chessboard[queens.size()][i] == '*') {
                continue;
            }
            queens.push_back(std::make_pair(queens.size(), i));
            find_solutions(queens, chessboard);
            queens.pop_back();
        }
    }
    else {
        return;
    }
}


int main() {
    string line;
    vector<string> chessboard;
    for (int i = 0; i < 8; i++) {
        cin >> line;
        chessboard.push_back(line);
    }
    vector<pair<int, int> > queens;
    find_solutions(queens, chessboard);
    std::cout << solution_count;
}