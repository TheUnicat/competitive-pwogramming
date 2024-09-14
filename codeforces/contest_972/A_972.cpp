//
// Created by TheUnicat on 2024-09-14.
//

#include <iostream>
#include <string>
using namespace std;

int t, n;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        string answer_str;
        int a_count = n / 5;
        int e_count = a_count;
        int i_count = e_count;
        int o_count = i_count;
        int u_count = o_count;
        if (a_count + e_count + i_count + o_count + u_count < n) {
            a_count++;
        }
        if (a_count + e_count + i_count + o_count + u_count < n) {
            e_count++;
        }
        if (a_count + e_count + i_count + o_count + u_count < n) {
            i_count++;
        }
        if (a_count + e_count + i_count + o_count + u_count < n) {
            o_count++;
        }

        for (int j = 0; j < a_count; j++) {
            answer_str += 'a';
        }
        for (int j = 0; j < e_count; j++) {
            answer_str += 'e';
        }
        for (int j = 0; j < i_count; j++) {
            answer_str += 'i';
        }
        for (int j = 0; j < o_count; j++) {
            answer_str += 'o';
        }
        for (int j = 0; j < u_count; j++) {
            answer_str += 'u';
        }


        cout << answer_str << endl;

    }
}