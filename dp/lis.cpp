#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // dp[i] will store the length of LIS ending at index i

    // Calculate the LIS ending at each index
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);  // If arr[i] is greater, extend the LIS
            }
        }
    }

    // The length of the longest increasing subsequence is the maximum value in dp
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;  // Input the number of elements in the sequence
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input the sequence
    }

    cout << "Length of Longest Increasing Subsequence: " << lis(arr) << endl;

    return 0;
}
