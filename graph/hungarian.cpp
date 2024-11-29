/*
Hungarian Algorithm
Description:
The Hungarian Algorithm is a combinatorial optimization method for solving the assignment problem in a weighted bipartite graph. It finds the minimum-cost matching of vertices between two disjoint sets.

Use Case:

Used in tasks like task assignment, job scheduling, or optimal resource allocation.
Suitable for problems where you need to pair entities from two groups optimally, minimizing or maximizing cost.

*/


const int INF = 1e9;

int hungarianAlgorithm(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);
        int j0 = 0;
        p[0] = i;

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;

            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= n; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }

            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    return -v[0];  // Minimum cost
}

int main() {
    vector<vector<int>> cost = {
        {4, 2, 3},
        {2, 1, 3},
        {3, 2, 4}
    };

    cout << "Minimum Cost: " << hungarianAlgorithm(cost) << endl;
}
