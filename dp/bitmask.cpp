/*
2. Bitmask DP
Description:
Bitmask DP is used to represent subsets of items or choices using bits. This is especially useful when solving combinatorial optimization problems where the goal is to explore all possible subsets efficiently.

Use Case:

Solving problems like the Traveling Salesman Problem (TSP) or subset sum problems.

 */


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n = 4;  // Number of nodes (cities)
vector<vector<int>> dist = {
    {0, 10, 15, 20},  // Distance matrix
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

vector<vector<int>> dp(1 << n, vector<int>(n, -1));

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {  // All cities are visited
        return dist[pos][0];  // Return to the start city
    }
    
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    
    int ans = INT_MAX;
    
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) {  // If the city is not yet visited
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city));
        }
    }
    
    return dp[mask][pos] = ans;
}

int main() {
    cout << "Minimum cost to visit all cities: " << tsp(1, 0) << endl;  // Start from city 0
    return 0;
}
