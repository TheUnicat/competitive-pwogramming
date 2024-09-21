//
// Created by TheUnicat on 2024-09-21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> prefix_arr(n, 0);
        vector<int> diff_arr(n + 1, 0);
        vector<int> curr_jobs_running(n, 0);
        vector<pair<int, int>> jobs_list(k);
        int jobs = 0;
        for (int j = 0; j < k; j++) {
            cin >> jobs_list[j].first >> jobs_list[j].second;
            diff_arr[jobs_list[j].first - 1]++;
            diff_arr[jobs_list[j].second]--;
        }
        sort(jobs_list.begin(), jobs_list.end());

        int curr_index = 0;
        for (int j = 0; j < n; j++) {
            if (curr_index != k) {
                while (jobs_list[curr_index].first == j + 1) {
                    jobs++;
                    curr_index++;
                    if (curr_index == k) break;
                }
            }
            prefix_arr[j] = jobs;
        }

        int n_jobs_now = 0;
        for (int j = 0; j < n; j++) {
            n_jobs_now += diff_arr[j];
            curr_jobs_running[j] = n_jobs_now;
        }

        int max_jobs = 0;
        int min_jobs = k;
        int max_jobs_ix = 1;
        int min_jobs_ix = 1;
        for (int j = 0; j <= n - d; j++) {
            int jobs_here = prefix_arr[j + d - 1] - prefix_arr[j] + curr_jobs_running[j];
            if (jobs_here > max_jobs) {
                max_jobs = jobs_here;
                max_jobs_ix = j + 1;
            }
            if (jobs_here < min_jobs) {
                min_jobs = jobs_here;
                min_jobs_ix = j + 1;
            }
        }


        cout << max_jobs_ix << " " << min_jobs_ix << endl;
    }
}