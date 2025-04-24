#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};

bool cmp(const Item& a, const Item& b) {
    return (long long)a.value * b.weight > (long long)b.value * a.weight;
}

bool validateInput(int W, const Item arr[], int n) {
    if (W <= 0 || n <= 0 || !arr) return false;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= 0 || arr[i].value < 0) return false;
    }
    return true;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}
