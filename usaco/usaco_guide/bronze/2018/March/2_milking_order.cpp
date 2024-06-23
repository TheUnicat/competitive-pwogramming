//
// Created by TheUnicat on 2024-06-18.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int n;
int k;
int m;

vector<pair<int, int> > constraints;
vector<int> cow_order;

bool is_combination_valid(vector<int> temporary) {
    vector<int> copy_cow_order = cow_order;
    for (int i = 0; i < n; i++) {
        if (temporary[i] == copy_cow_order[0]) {
            copy_cow_order.erase(copy_cow_order.begin());
        }
        else if (find(copy_cow_order.begin(), copy_cow_order.end(), temporary[i]) != copy_cow_order.end()) {
            return false;
        }
    }
    return true;
}


bool check_valid(int i) {
    i--;
    vector<int> copy_cow_order = cow_order;
    auto it = std::find(copy_cow_order.begin(), copy_cow_order.end(), 1);
    if (it != copy_cow_order.end()) {
        copy_cow_order.erase(it);
    }

    vector<int> temporary(n, 0);

    for (auto constraint : constraints) {
        temporary[constraint.second] = constraint.first;
        if (find(copy_cow_order.begin(), copy_cow_order.end(), constraint.first) != copy_cow_order.end()) {
            copy_cow_order.erase(find(copy_cow_order.begin(), copy_cow_order.end(), constraint.first));
        }
    }

    if (temporary[i] != 0) {
        cout << "false" << i;
        return false;
    }
    temporary[i] = 1;

    for (int j = 0; j < n; j++) {
        if (temporary[j] != 0) {
            continue;
        }

        temporary[j] = copy_cow_order[0];

        if (is_combination_valid(temporary)) {
            copy_cow_order.erase(copy_cow_order.begin());
        }
        else {
            temporary[j] = 0;
        }
    }

    if (copy_cow_order.size() == 0) {
        return true;
    }
    return false;
}


int main() {
    int line_num = 1;
    string line;
    ifstream infile("milkorder.in");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line_num == 1) {
            iss >> n >> m >> k;
        }
        else if (line_num == 2) {
            int num;
            while (iss >> num) {
                cow_order.push_back(num);
            }
        }
        else {
            int constraint_num;
            int constraint_pos;
            iss >> constraint_num >> constraint_pos;
            constraints.push_back(make_pair(constraint_num, constraint_pos - 1));
        }
        line_num++;
    }

    for (int i = 1; i < n + 1; i++) {
        if (check_valid(i)) {
            ofstream outfile("milkorder.out");
            outfile << i;
            outfile.close();
        }
    }
}