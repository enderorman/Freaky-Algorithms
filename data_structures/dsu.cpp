/*
3. Disjoint Set Union (Union-Find)
Description:
DSU efficiently handles connected component queries and merges sets.

Path compression and union by rank optimize operations.
Use Case:

Used in algorithms like Kruskal's MST, cycle detection, and connected components.

*/

#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    cout << "Are 0 and 2 connected? " << (dsu.find(0) == dsu.find(2)) << endl;  // Output: 1 (true)
    cout << "Are 0 and 3 connected? " << (dsu.find(0) == dsu.find(3)) << endl;  // Output: 0 (false)
}
