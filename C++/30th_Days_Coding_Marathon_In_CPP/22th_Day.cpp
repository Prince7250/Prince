//1) Job Scheduling with deadlines
// Mr. Amit have some jobs to be scheduled. Each job must meet the deadline to be counted as completed i.e. scheduling a job after its deadline is of no use.
// Each job has some profit associated with it. Mr. Amit wants to schedule the as much jobs as he can and also want to earn the maximum profit.
// Note: Each job needs 1 time unit for execution.
// Input Format:
// The 1st line contains an integer N, the number of jobs.
// The 2nd line contains N integers separated by space denoting deadline times of N jobs.
// The 3rd line contains N integers separated by space denoting profits of N jobs.
// Output Format:
// Print the maximum profit that can be earned.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int find(vector<int> &parent, int x) {
//     if (parent[x] == x) return x;
//     return parent[x] = find(parent, parent[x]);
// }

// void merge(vector<int> &parent, int u, int v) {
//     parent[u] = v;
// }

// int jobScheduling(vector<int> deadlines, vector<int> profits) {
//     int n = deadlines.size();
//     vector<pair<int, int>> jobs;
//     for (int i = 0; i < n; i++) {
//         jobs.push_back({profits[i], deadlines[i]});
//     }
//     sort(jobs.rbegin(), jobs.rend());
//     vector<int> parent(101);
//     for (int i = 0; i < 101; i++) parent[i] = i;
//     int maxProfit = 0;
//     for (auto job : jobs) {
//         int profit = job.first;
//         int deadline = job.second;
//         int availableSlot = find(parent, deadline);
//         if (availableSlot > 0) {
//             maxProfit += profit;
//             merge(parent, availableSlot, availableSlot - 1);
//         }
//     }
//     return maxProfit;
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<int> deadlines(N), profits(N);

//     for (int i = 0; i < N; i++) cin >> deadlines[i];
//     for (int i = 0; i < N; i++) cin >> profits[i];

//     cout << jobScheduling(deadlines, profits) << endl;
//     return 0;
// }

// 0-1 Knapsack problem
// The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
// In this problem we will solve a variant of it, in which the items can have a binary decision only i.e. either you can pick the item or leave it. No partial items allowed to fill the bag at fullest. This is also known as 0-1 knapsack problem.
// Given two integer arrays values[0..n-1] and weight[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of values[] such that sum of the weights of this subset is smaller than or equal to W.
// Note: You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

#include <iostream>
#include <vector>
using namespace std;

int zeroOneKnapsack(int val[], int weight[], int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    int val[n], weight[n];

    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> weight[i];

    cout << zeroOneKnapsack(val, weight, n, capacity) << endl;
    return 0;
}

