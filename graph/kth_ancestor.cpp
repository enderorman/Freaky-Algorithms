/*

To find the Kth ancestor of a node in a tree, we can use the Binary Lifting technique, which preprocesses the tree to allow fast querying of ancestors.

Approach:
Binary Lifting Preprocessing:
Precompute an array up[node][i] where up[node][i] is the 
2
i
2 
i
 -th ancestor of the node. This allows you to jump upwards by powers of two during queries.
The key observation is that to find the Kth ancestor of a node, you can break K into a sum of powers of two and jump upwards in logarithmic steps.
Querying:
To find the Kth ancestor, decompose K into its binary representation. Then for each bit in the binary representation, jump by powers of two to reach the ancestor.


Time Complexity:
Preprocessing: 
O
(
n
log
⁡
n
)
O(nlogn) due to the DFS and filling of the binary lifting table.
Query: 
O
(
log
⁡
n
)
O(logn) for each Kth ancestor query because we are jumping through powers of 2 (binary lifting).

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class LCA {
public:
    int n, LOG;
    vector<vector<int>> up; // up[node][i] stores 2^i-th ancestor of node
    vector<int> depth;

    LCA(int nodes) {
        n = nodes;
        LOG = log2(n) + 1; // Max power of 2 we need
        up = vector<vector<int>>(n, vector<int>(LOG, -1)); // Initialize with -1
        depth = vector<int>(n, 0); // Depth of nodes
    }

    // DFS to preprocess the `up` table
    void dfs(int node, int parent, const vector<vector<int>>& tree) {
        up[node][0] = parent; // Direct parent (2^0-th ancestor)
        for (int i = 1; i < LOG; ++i) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1]; // 2^i-th ancestor
            }
        }
        for (int child : tree[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node, tree);
            }
        }
    }

    // Preprocess the tree, takes the root (usually node 0) and tree as input
    void preprocess(int root, const vector<vector<int>>& tree) {
        dfs(root, -1, tree);
    }

    // Function to find the Kth ancestor of a given node
    int getKthAncestor(int node, int K) {
        for (int i = LOG - 1; i >= 0; --i) {
            if (K >= (1 << i)) {
                node = up[node][i];
                if (node == -1) return -1; // If there's no such ancestor
                K -= (1 << i);
            }
        }
        return node;
    }
};

int main() {
    int n, q;
    cin >> n; // Number of nodes
    vector<vector<int>> tree(n);

    // Input the tree edges
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert to 0-based index
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    LCA lca(n);
    lca.preprocess(0, tree); // Preprocess the tree with root as node 0

    // Input and process queries
    cin >> q; // Number of queries
    while (q--) {
        int node, K;
        cin >> node >> K;
        node--; // Convert to 0-based index
        int ancestor = lca.getKthAncestor(node, K);
        cout << ancestor + 1 << endl; // Convert to 1-based index for output
    }

    return 0;
}
