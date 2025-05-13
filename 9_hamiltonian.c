#include <stdio.h>

#define V 5 // Number of vertices

// Adjacency matrix: 1 means there's an edge between vertices, 0 means no edge
int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}};

// Array to keep track of visited vertices
int visited[V];

// Function to check if we can complete the cycle starting from vertex 'current'
int hamiltonianCycleExists(int current, int count, int start)
{
    // If all vertices are visited, check if last vertex connects back to the start
    if (count == V)
    {
        return graph[current][start]; // Return 1 if there's an edge from last to start
    }

    // Try all other vertices
    for (int v = 0; v < V; v++)
    {
        // Check if vertex 'v' is connected and not visited yet
        if (graph[current][v] && !visited[v])
        {
            visited[v] = 1; // Mark vertex 'v' as visited

            // Recurse to try to complete the cycle
            if (hamiltonianCycleExists(v, count + 1, start))
                return 1; // Cycle found
            else
                visited[v] = 0; // Backtrack, mark 'v' as unvisited
        }
    }

    return 0; // No cycle found from current vertex
}

int main()
{
    // Initialize visited array (set all vertices as unvisited initially)
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    visited[0] = 1; // Start the cycle from vertex 0

    // Call the function to check if Hamiltonian cycle exists
    if (hamiltonianCycleExists(0, 1, 0))
        printf("Hamiltonian cycle exists.\n");
    else
        printf("Hamiltonian cycle does not exist.\n");

    return 0;
}
