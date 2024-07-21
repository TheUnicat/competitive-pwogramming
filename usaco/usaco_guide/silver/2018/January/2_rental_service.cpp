//
// Created by TheUnicat on 2024-07-21.
//

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m, r;
int current_customer = 0;
ll profit;
vector<int> cows;
vector<pair<int, int> > milk_consumers;
vector<int> rentals;

bool comp_pair(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

ll milk_consumer_revenue(int gallons) {
    ll revenue = 0;
    for (int i = current_customer; i < milk_consumers.size(); i++) {
        auto customer = milk_consumers[i];
        revenue += min(customer.first, gallons) * customer.second;
        gallons -= min(customer.first, gallons);
        if (gallons == 0) break;
    }

    return revenue;
}

void milk_cow() {
    int gallons = cows[cows.size() - 1];
    ll revenue = 0;
    for (int i = current_customer; i < milk_consumers.size(); i++) {
        revenue += min(milk_consumers[i].first, gallons) * milk_consumers[i].second;
        int gallons_sold = min(milk_consumers[i].first, gallons);
        gallons -= min(milk_consumers[i].first, gallons);
        milk_consumers[i].first -= gallons_sold;
        if (milk_consumers[i].first == 0) current_customer++;
        if (gallons == 0) break;
    }
    profit += revenue;
    cows.pop_back();
}

void rent_cow() {
    profit += rentals[0];
    rentals.erase(rentals.begin());
    cows.erase(cows.begin());
}

int main() {
    ifstream infile("rental.in");
    infile >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        int cow;
        infile >> cow;
        cows.push_back(cow);
    }
    for (int i = 0; i < m; i++) {
        int gallons, price;
        infile >> gallons >> price;
        milk_consumers.push_back(make_pair(gallons, price));
    }
    for (int i = 0; i < r; i++) {
        int rent;
        infile >> rent;
        rentals.push_back(rent);
    }
    infile.close();

    sort(cows.begin(), cows.end());
    sort(milk_consumers.begin(), milk_consumers.end(), comp_pair);
    sort(rentals.begin(), rentals.end(), greater<int>());
    rentals.push_back(-1);

    while (true) {
        if (cows.empty()) break;
        int cow = cows[0];
        if (milk_consumer_revenue(cow) > rentals[0]) {
            milk_cow();
        }
        else {
            rent_cow();
        }
    }

    ofstream outfile("rental.out");
    outfile << profit;
    outfile.close();
}