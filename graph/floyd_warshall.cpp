/*

Floyd-Warshall Algorithm
The basic idea of the algorithm is to progressively improve the estimate of the shortest paths between each pair of nodes by considering whether an intermediate node can provide a shorter path between any two nodes. It's based on dynamic programming and works with graphs that may have negative edge weights, but no negative weight cycles.


Time Complexity
The time complexity of this algorithm is 
O
(
n
3
)
O(n 
3
 ), where n is the number of nodes in the graph. This is because we have three nested loops: one for each node as the intermediate node, and two for each pair of nodes being considered.
Use Cases for Floyd-Warshall Algorithm
All-Pairs Shortest Path: If you need to compute the shortest paths between all pairs of nodes in a graph, Floyd-Warshall is ideal. It's efficient for dense graphs where Dijkstra's algorithm would require many calls.
Graph with Negative Edge Weights: Unlike algorithms like Dijkstra's, Floyd-Warshall can handle graphs with negative edge weights. It will also correctly report negative cycles, which is useful in certain graph-related problems like finding arbitrage opportunities in currency exchange rates.
Transitive Closure: The Floyd-Warshall algorithm can be used to compute the transitive closure of a directed graph. In the context of reachability, if dist[i][j] is not INT_MAX, it means there's a path from i to j.
Network Routing: In networking, you may need to know the shortest path between every pair of nodes, especially for routing protocols in computer networks.

*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int n) {
    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n = 4; // Number of nodes in the graph
    
    // Initialize the distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Distance from a node to itself is 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Add edges to the graph (example graph)
    dist[0][1] = 5;
    dist[0][2] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;

    // Run Floyd-Warshall
    floydWarshall(dist, n);

    // Print the shortest distance matrix
    cout << "Shortest distance matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
