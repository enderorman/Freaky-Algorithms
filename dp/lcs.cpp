#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    
    // dp[i][j] will store the length of LCS of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match, extend LCS
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Take the max of excluding one character
            }
        }
    }

    return dp[n][m];  // The length of the longest common subsequence is at dp[n][m]
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;  // Input two strings

    cout << "Length of Longest Common Subsequence: " << lcs(s1, s2) << endl;

    return 0;
}
