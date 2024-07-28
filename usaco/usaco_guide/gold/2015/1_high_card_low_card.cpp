//
// Created by TheUnicat on 2024-07-28.
//

#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ifstream infile("cardgame.in");
    infile >> n;
    set<int> bessie_cards;
    vector<int> card_order_high;
    vector<int> card_order_low;
    for (int i = 1; i <= 2 * n; i++) bessie_cards.insert(i);
    for (int i = 0; i < n / 2; i++) {
        int card;
        infile >> card;
        bessie_cards.erase(card);
        card_order_high.push_back(card);
    }
    for (int i = n / 2; i < n; i++) {
        int card;
        infile >> card;
        bessie_cards.erase(card);
        card_order_low.push_back(card);
    }
    infile.close();

    sort(card_order_high.begin(), card_order_high.end());
    sort(card_order_low.begin(), card_order_low.end());

    int total_points = 0;

    for (int i = 0; i < n / 2; i++) {
        int elsie_card = card_order_high[(n / 2) - i - 1];
        auto it = bessie_cards.end();
        it--;
        if (*it > elsie_card) {
            bessie_cards.erase(it);
            total_points++;
        }
    }

    for (int i = n / 2; i < n; i++) {
        int elsie_card = card_order_low[i - n / 2];
        auto it = bessie_cards.upper_bound(elsie_card);
        if (it == bessie_cards.begin()) continue;
        it--;
        if (*it < elsie_card) {
            bessie_cards.erase(it);
            total_points++;
        }
    }

    ofstream outfile("cardgame.out");
    outfile << total_points;
    outfile.close();
}