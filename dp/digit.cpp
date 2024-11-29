/*
3. Digit DP
Description:
Digit DP is used to solve problems involving numbers with specific properties on their digits. It allows efficient counting or checking of numbers that satisfy certain constraints, such as the number of valid numbers with a certain number of digits and specific properties (like divisibility).

Use Case:

Problems like counting numbers with certain digit constraints (e.g., numbers divisible by 3, numbers containing certain digits, etc.)

*/


#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> dp(20, vector<vector<int>>(2, vector<int>(2, -1)));

int countNumbers(int pos, bool tight, bool nonZero, const string& s) {
    if (pos == s.size()) {
        return nonZero;  // We return 1 if we have formed a valid number, else 0.
    }

    if (dp[pos][tight][nonZero] != -1) {
        return dp[pos][tight][nonZero];
    }

    int limit = tight ? s[pos] - '0' : 9;
    int result = 0;

    for (int dig = 0; dig <= limit; ++dig) {
        result += countNumbers(pos + 1, tight && (dig == limit), nonZero || (dig > 0), s);
    }

    return dp[pos][tight][nonZero] = result;
}

int main() {
    string s = "123";  // Counting numbers from 1 to 123
    cout << "Number of valid numbers: " << countNumbers(0, true, false, s) << endl;
    return 0;
}
