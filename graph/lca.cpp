void dfsLCA(int u, int parent, vector<int>& depth, vector<vector<int>>& up, vector<vector<int>>& adj, int log) {
    up[u][0] = parent;
    for (int i = 1; i <= log; i++) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    for (int v : adj[u]) {
        if (v != parent) {
            depth[v] = depth[u] + 1;
            dfsLCA(v, u, depth, up, adj, log);
        }
    }
}

int lca(int u, int v, vector<int>& depth, vector<vector<int>>& up, int log) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = log; i >= 0; i--) {
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = log; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int main() {
    int n = 7, log = log2(n) + 1;
    vector<vector<int>> adj(n);
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[1].push_back(4); adj[4].push_back(1);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[2].push_back(6); adj[6].push_back(2);

    vector<int> depth(n, 0);
    vector<vector<int>> up(n, vector<int>(log + 1, -1));
    dfsLCA(0, -1, depth, up, adj, log);

    cout << "LCA of 3 and 4: " << lca(3, 4, depth, up, log) << endl;
    cout << "LCA of 5 and 6: " << lca(5, 6, depth, up, log) << endl;
    cout << "LCA of 3 and 5: " << lca(3, 5, depth, up, log) << endl;
}
