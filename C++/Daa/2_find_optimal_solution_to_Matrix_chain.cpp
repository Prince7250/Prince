#include <bits/stdc++.h>

using namespace std;

int MatrixChainOrder(vector<int>& p, int i, int j) {
    if (i == j)
        return 0;
    int minVal = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        minVal = min(minVal, count);
    }
    return minVal;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int N = arr.size();
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, N - 1) << endl;
    return 0;
}
