#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    
    // Base case: sum 0 can always be formed with an empty set
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][sum];  // If we can form the target sum, return true
}

int main() {
    int n, sum;
    cin >> n >> sum;  // Input number of elements and target sum
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (subsetSum(nums, sum)) {
        cout << "Subset with sum " << sum << " exists!" << endl;
    } else {
        cout << "No subset with sum " << sum << " exists." << endl;
    }
    
    return 0;
}
