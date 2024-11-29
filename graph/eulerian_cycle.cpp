/*
Eulerian Cycle
Description:
An Eulerian Cycle is a path that visits every edge in the graph exactly once and returns to the starting vertex.

Use Case:

Used in applications like route planning (e.g., garbage collection, mail delivery) and network connectivity.
Applicable in tasks where you need to traverse every edge exactly once.

*/


void findEulerianCycle(vector<vector<int>>& adj, int u, vector<int>& cycle) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (*it == u) {
                adj[v].erase(it);
                break;
            }
        }
        findEulerianCycle(adj, v, cycle);
    }
    cycle.push_back(u);
}

int main() {
    int n = 3;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);

    vector<int> cycle;
    findEulerianCycle(adj, 0, cycle);

    cout << "Eulerian Cycle: ";
    for (int v : cycle) cout << v << " ";
    cout << endl;
}
