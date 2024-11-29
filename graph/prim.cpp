int prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> minWeight(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int mstWeight = 0;
    minWeight[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [weight, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += weight;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < minWeight[v]) {
                minWeight[v] = w;
                pq.emplace(w, v);
            }
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    adj[0].push_back({3, 2});
    adj[3].push_back({0, 2});

    int mstWeight = prim(n, adj);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
}
