#include <stdio.h>

int main() {

    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int u[E], v[E];
    int visitedV[V];

    for(int i = 0; i < V; i++)
        visitedV[i] = 0;

    printf("Enter edges (u v):\n");

    for(int i = 0; i < E; i++)
        scanf("%d %d", &u[i], &v[i]);

    printf("\nVertex Cover Set:\n");

    for(int i = 0; i < E; i++) {

        if(visitedV[u[i]] == 0 && visitedV[v[i]] == 0) {

            visitedV[u[i]] = 1;
            visitedV[v[i]] = 1;

            printf("%d %d\n", u[i], v[i]);
        }
    }

    return 0;
}