#include <stdio.h>

#define V 5     // Number of vertices
#define E 8     // Number of edges
#define INF 99999

int main() {
    // Each edge: u -> v with weight w
    int edges[E][3] = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {3, 1, -2},
        {4, 3, 7},
        {2, 4, 9}
    };

    int dist[V];         // Distance from source to each vertex
    int i, j;
    int source = 0;      // Starting vertex

    // Step 1: Initialize all distances to infinity
    for (i = 0; i < V; i++)
        dist[i] = INF;
    dist[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (i = 0; i < V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for (j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return 0;
        }
    }

    // Step 4: Print the distances
    printf("Vertex\tDistance from Source %d\n", source);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
