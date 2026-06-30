// WAP to implement Dijkstra’s algorithm for finding shortest path.

#include <iostream>
#include <climits>
using namespace std;

// Function to print path
void printPath(const int parent[], int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

// Dijkstra function
void dijkstra(int graph[20][20], int src, int n) {
    int dist[20];
    bool visited[20];
    int parent[20];

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX, minIndex = -1;

        // Find minimum distance vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = true;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (graph[minIndex][v] && !visited[v] &&
                dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) {

                dist[v] = dist[minIndex] + graph[minIndex][v];
                parent[v] = minIndex;
            }
        }
    }

    // Output
    cout << "\nVertex\tDistance\tPath\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";

        if (dist[i] == INT_MAX) {
            cout << "INF\t\t-\n";
        } else {
            cout << dist[i] << "\t\t";
            printPath(parent, i);
            cout << endl;
        }
    }
}

// Main function
int main() {
    int graph[20][20] = {0};
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w; // For undirected graph
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, src, n);

    return 0;
}