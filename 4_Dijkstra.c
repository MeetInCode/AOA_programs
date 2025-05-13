#include <stdio.h>

#define V 5       // Total number of vertices in the graph
#define INF 99999 // A value representing infinity (used for unreachable vertices)

int main() {
    // Hardcoded graph using an adjacency matrix
    // graph[i][j] is the weight from vertex i to j
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int dist[V];      // dist[i] stores shortest distance from source to i
    int visited[V];   // visited[i] is 1 if vertex i is included in shortest path tree

    int i, j, min, u;

    // Step 1: Initialize all distances as INF and visited[] as 0
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    int source = 0;     // Starting node
    dist[source] = 0;   // Distance from source to itself is always 0

    // Step 2: Repeat V-1 times (standard for Dijkstra)
    for (i = 0; i < V - 1; i++) {
        min = INF;
        u = -1;

        // Step 2a: Pick the unvisited vertex with the smallest distance
        for (j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;  // Mark vertex u as visited

        // Step 2b: Update distances of adjacent vertices of u
        for (j = 0; j < V; j++) {
            // If there is an edge from u to j, j is not visited,
            // and path through u is shorter than current dist[j], update it
            //? if edge exists, vertex is not visited, and path through u is shorter than current dist[j], update it    
            if (graph[u][j] && !visited[j] && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Step 3: Print the final shortest distances from source to all vertices
    printf("Vertex\tDistance from Source %d\n", source);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
