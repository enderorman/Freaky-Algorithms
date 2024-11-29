/*
1. Tree DP
Description:
Tree DP is a dynamic programming technique applied to tree structures. It is useful when you need to process or calculate values based on the structure of a tree, typically involving subtree computations. The most common approach is post-order traversal of the tree.

Use Case:

Solving problems like finding the maximum sum path in a tree, counting paths, or solving problems with subtree values.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> dp;

void dfs(int node, int parent) {
    dp[node] = 1; // Base case: The node itself contributes a value of 1.
    
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            dp[node] += dp[child];  // Add the subtree size to the current node
        }
    }
}

int main() {
    int n = 6;  // Number of nodes
    tree.resize(n);
    dp.resize(n, 0);
    
    // Build the tree (Undirected Graph)
    tree[0] = {1, 2};
    tree[1] = {0, 3, 4};
    tree[2] = {0};
    tree[3] = {1};
    tree[4] = {1};
    
    dfs(0, -1);  // Start DFS from node 0
    
    // The dp array now holds the size of each subtree
    for (int i = 0; i < n; ++i) {
        cout << "Subtree size rooted at " << i << ": " << dp[i] << endl;
    }
    
    return 0;
}
