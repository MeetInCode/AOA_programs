#include <stdio.h>

#define V 5       // Number of vertices
#define INF 99999 // Infinity value for unreachable paths

// Step 1: Find the unvisited vertex with the minimum distance
int findMinVertex(int dist[], int visited[])
{
    int min = INF, minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Step 2: Run Dijkstra's algorithm from the source vertex
void dijkstra(int graph[V][V], int source)
{
    int dist[V], visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // Find shortest paths to all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinVertex(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the final shortest distances
    printf("Vertex\tDistance from Source %d\n", source);
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

// Step 3: Driver code
int main()
{
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 4},
        {0, 0, 1, 4, 0}};

    int source = 0;
    printf("Dijkstra's Algorithm (Source: %d)\n", source);
    dijkstra(graph, source);

    return 0;
}
