void topologicalSort(int n, vector<vector<int>>& adj, vector<int>& order) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> order;
    topologicalSort(n, adj, order);

    cout << "Topological Order: ";
    for (int v : order) cout << v << " ";
    cout << endl;
}
