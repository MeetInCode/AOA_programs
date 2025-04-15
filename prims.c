#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define INF 9999999 // A large value to represent infinity

// Number of vertices in the graph
#define V 5

// Adjacency matrix representation of the graph
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    int no_edges = 0; // Number of edges in the MST

    // Array to track selected vertices (true if included in MST)
    bool selected[V];
    memset(selected, false, sizeof(selected)); // Initialize all vertices as not selected

    selected[0] = true; // Start from the first vertex
    printf("Edge : Weight\n");

    while (no_edges < V - 1)
    {
        int min = INF;
        int x = 0; // Row index
        int y = 0; // Column index

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // Not yet selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edges++;
    }

    return 0;
}
