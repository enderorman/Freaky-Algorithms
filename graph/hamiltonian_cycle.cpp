/*

Hamiltonian Cycle
Description:
The Hamiltonian Cycle algorithm checks if there is a cycle in a graph that visits every vertex exactly once and returns to the starting vertex.

Use Case:

Applicable in Traveling Salesman Problem (TSP) and path optimization tasks.
Used when you need to find a path covering all vertices exactly once (if one exists).

 */


bool hamiltonianCycle(vector<vector<int>>& graph, vector<int>& path, int pos, int n) {
    if (pos == n) return graph[path[pos - 1]][path[0]];

    for (int v = 1; v < n; v++) {
        if (find(path.begin(), path.begin() + pos, v) == path.begin() + pos && graph[path[pos - 1]][v]) {
            path[pos] = v;
            if (hamiltonianCycle(graph, path, pos + 1, n)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    vector<int> path(n, -1);
    path[0] = 0;
    if (hamiltonianCycle(graph, path, 1, n)) {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian Cycle found." << endl;
    }
}
