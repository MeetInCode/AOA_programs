#include <stdio.h>
#include <stdbool.h>
#define INF 9999999 // A large value to represent infinity

// Number of vertices in the graph
#define V 5

// Adjacency matrix representation of the graph
// If G[i][j] = 0, no edge between i and j
// If G[i][j] > 0, there is an edge with weight G[i][j]
int G[V][V] = {
    {0, 9, 75, 0, 0},    // Vertex 0 connects to 1 (weight 9) and 2 (weight 75)
    {9, 0, 95, 19, 42},  // Vertex 1 connects to 0,2,3,4
    {75, 95, 0, 51, 66}, // Vertex 2 connects to 0,1,3,4
    {0, 19, 51, 0, 31},  // Vertex 3 connects to 1,2,4
    {0, 42, 66, 31, 0}   // Vertex 4 connects to 1,2,3
};

int main()
{
    // PRIM'S ALGORITHM FOR MINIMUM SPANNING TREE (MST)

    int no_edges = 0; // Counter for edges in the MST (will be V-1 when complete)

    // Array to track which vertices are already included in MST
    bool selected[V] = {false}; // Initialize all elements to false directly

    // Start the MST from vertex 0
    selected[0] = true;
    printf("Edge : Weight\n");

    // MST will have (V-1) edges for V vertices
    while (no_edges < V - 1)
    {
        // Variables to track the minimum edge in each iteration
        int min = INF;
        int x = 0; // Source vertex of the edge
        int y = 0; // Destination vertex of the edge

        // CORE OF PRIM'S ALGORITHM:
        // Find the minimum weight edge that connects a vertex in MST
        // to a vertex not yet in MST
        for (int i = 0; i < V; i++)
        {
            if (selected[i]) // If vertex i is in MST
            {
                for (int j = 0; j < V; j++)
                {
                    // Check if vertex j is:
                    // 1. Not in MST yet
                    // 2. There is an edge between i and j
                    if (!selected[j] && G[i][j])
                    {
                        // If this edge has lower weight than current minimum
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

        // Add the new edge to MST and print it
        printf("%d - %d : %d\n", x, y, G[x][y]);

        // Mark the new vertex as part of MST
        selected[y] = true;

        // Increment edge counter
        no_edges++;
    }

    return 0;
}
