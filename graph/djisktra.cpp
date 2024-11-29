#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, int src, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 10});
    adj[0].push_back({3, 5});
    adj[1].push_back({2, 1});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 8});
    adj[3].push_back({4, 2});
    adj[4].push_back({2, 4});

    vector<int> dist = dijkstra(n, 0, adj);
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }
}
