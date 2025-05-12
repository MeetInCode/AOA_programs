#include <stdio.h>

#define V 4
#define INF 99999

// Print the final distance matrix
void printMatrix(int dist[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall algorithm
void floydWarshall(int graph[V][V])
{
    int dist[V][V];

    // Step 1: Initialize distance matrix with original graph values
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Step 2: Update distances using each vertex as an intermediate
    for (int k = 0; k < V; k++)
    { // Intermediate vertex
        for (int i = 0; i < V; i++)
        { // Source vertex
            for (int j = 0; j < V; j++)
            { // Destination vertex
                // Step 3: If path i->k and k->j exist, check if shorter than i->j
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j])
                        dist[i][j] = newDist;
                }
            }
        }
    }

    // Step 4: Print the result
    printMatrix(dist);
}

int main()
{
    // Input graph as adjacency matrix
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    floydWarshall(graph);
    return 0;
}
