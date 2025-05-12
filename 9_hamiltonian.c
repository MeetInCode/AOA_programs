#include <stdio.h>

#define V 5  // Number of vertices in the graph

// Adjacency matrix representation of the graph
// graph[i][j] = 1 if there's an edge between vertex i and vertex j, else 0
int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int path[V];  // Array to store the solution path (the order of vertices in the Hamiltonian cycle)

int isSafe(int v, int pos) {
    // Check if the vertex v can be added to the path at position pos

    // 1. Check if the vertex v is adjacent to the last vertex in the path
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // 2. Check if vertex v has already been included in the path (no repeats)
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;  // If both checks pass, the vertex is safe to add
}

int hamiltonianCycleUtil(int pos) {
    // Try to find the Hamiltonian cycle by recursively adding vertices to the path
    // pos indicates the current position in the path being considered

    if (pos == V) {  // All vertices are included in the path
        // Check if there is an edge from the last vertex to the first vertex to form a cycle
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;  // Hamiltonian cycle found
        return 0;  // No cycle found
    }

    // Try to add each vertex to the path
    for (int v = 1; v < V; v++) {
        // Check if it's safe to add vertex v at position pos
        if (isSafe(v, pos)) {
            path[pos] = v;  // Add vertex v to the path

            // Recursively try to complete the path
            if (hamiltonianCycleUtil(pos + 1))
                return 1;  // Cycle found, return success

            // If adding v doesn't lead to a solution, backtrack (remove v from path)
            path[pos] = -1;  // Backtrack by resetting the current position
        }
    }
    return 0;  // No valid vertex found, return failure
}

void printSolution() {
    // Print the Hamiltonian cycle solution (if found)
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("\n");
}

int main() {
    // Initialize the path array to -1, indicating that no vertices are included yet
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Starting vertex of the Hamiltonian cycle (can be any vertex, here we choose 0)

    // Try to find the Hamiltonian cycle starting from the second vertex (index 1)
    if (hamiltonianCycleUtil(1) == 1)
        printSolution();  // Print the solution if a cycle is found
    else
        printf("Solution does not exist.\n");  // If no cycle is found, print a message

    return 0;
}
