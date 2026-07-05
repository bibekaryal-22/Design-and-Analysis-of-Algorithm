// WAP to implement Prim’s algorithm for finding MST.
#include <iostream>
using namespace std;
#include <climits>

int main() {
    int n, e;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    int graph[20][20] = {0};
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // For undirected graph
    }

    // Prim's algorithm implementation
    int parent[20], key[20];
    bool mstSet[20] = {false};

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        mstSet[minIndex] = true;

        for (int v = 0; v < n; v++) {
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << graph[parent[i]][i] << ")" << endl;
    }

    return 0;
}