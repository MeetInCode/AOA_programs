#include <stdio.h>

#define V 5       // Number of vertices in the graph
#define INF 99999 // Infinity value to represent unreachable paths in the graph

// Step 1: Function to find the unvisited vertex with the minimum distance
int findMinVertex(int dist[], int visited[]) {
    int min = INF, minIndex = -1;

    //? Loop through all vertices to find the one with the minimum distance that is unvisited
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];          // Update min distance
            minIndex = i;          // Update vertex index
        }
    }
    return minIndex;              // Return vertex with the minimum distance
}

// Step 2: Run Dijkstra's algorithm from the source vertex
void dijkstra(int graph[V][V], int source) {
    int dist[V], visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;           // Set all distances to infinity
        visited[i] = 0;          // Mark all vertices as unvisited
    }
    dist[source] = 0;             // Distance to source is 0

    // Find the shortest paths for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(dist, visited);   // Get vertex with minimum distance
        visited[u] = 1;                         // Mark it as visited

        // Update distances for all adjacent vertices of u
        //! visited[v]: The vertex v has not been visited yet.
        //! graph[u][v]: There is no edge from u to v.
        //! dist[u] + graph[u][v] < dist[v]: The path through u offers a shorter distance to v than the currently known distance.

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; // Relax the edge if a shorter path is found
            }
        }
    }

    // Print the final shortest distances from the source
    printf("Vertex\tDistance from Source %d\n", source);
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);    // Print vertex and its distance from the source
    }
}

// Step 3: Driver code
int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 4},
        {0, 0, 1, 4, 0}
    };

    int source = 0;                         // Set source vertex to 0
    printf("Dijkstra's Algorithm (Source: %d)\n", source);
    dijkstra(graph, source);                // Call the Dijkstra function to find shortest paths

    return 0;
}
