vector<int> desopoPape(int n, int src, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    deque<int> dq;
    dist[src] = 0;
    dq.push_back(src);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 2});
    adj[1].push_back({2, -1});
    adj[1].push_back({3, 4});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 2});

    vector<int> dist = desopoPape(n, 0, adj);
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }
}
