vector<int> bellmanFord(int n, int src, vector<tuple<int, int, int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            throw runtime_error("Negative weight cycle detected!");
        }
    }

    return dist;
}

int main() {
    int n = 5; 
    vector<tuple<int, int, int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    try {
        vector<int> dist = bellmanFord(n, 0, edges);
        for (int i = 0; i < n; i++) {
            cout << "Distance to " << i << ": " << dist[i] << endl;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
