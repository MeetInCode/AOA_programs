#include <stdio.h>
#include <limits.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

// Bellman-Ford algorithm
void BellmanFord(int edges[MAX_EDGES][3], int V, int E, int src)
{
    int dist[MAX_VERTICES];

    // Step 1: Initialize distances to all vertices as infinite (INT_MAX)
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; // Distance to the source is 0

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];      // Source vertex of the edge
            int v = edges[j][1];      // Destination vertex of the edge
            int weight = edges[j][2]; // Weight of the edge

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print the distances from the source vertex
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            printf("%d \t\t INF\n", i);
        }
        else
        {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main()
{
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Array to store edges in the format [source, destination, weight]
    int edges[MAX_EDGES][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    // Run Bellman-Ford algorithm from vertex 0
    BellmanFord(edges, V, E, 0);

    return 0;
}
