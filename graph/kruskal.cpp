class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
};

int kruskal(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mstWeight = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mstWeight += w;
        }
    }

    return mstWeight;
}

int main() {
    int n = 4; // Number of nodes
    vector<tuple<int, int, int>> edges = {
        {1, 0, 1}, {2, 1, 2}, {1, 2, 3}, {2, 0, 3}, {3, 0, 2}
    };

    int mstWeight = kruskal(n, edges);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
}
