#include <stdio.h>

#define V 4  // Number of vertices in the graph
#define M 3  // Number of colors

int graph[V][V] = {  // The adjacency matrix representation of the graph
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[V];  // Array to store the color assigned to each vertex

// Function to check if it's safe to color vertex 'v' with color 'c'
int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;  // If adjacent vertex has the same color, not safe
        }
    }
    return 1;  // It's safe to color vertex 'v' with color 'c'
}

// Backtracking function to solve the graph coloring problem
int graphColoring(int v) {
    // Base case: if all vertices are assigned a color, return true
    if (v == V) {
        return 1;  // All vertices are colored successfully
    }

    // Try all colors for vertex 'v'
    for (int c = 1; c <= M; c++) {
        // Check if it's safe to color vertex 'v' with color 'c'
        if (isSafe(v, c)) {
            color[v] = c;  // Assign color 'c' to vertex 'v'
            if (graphColoring(v + 1)) {
                return 1;  // If successful, return true
            }
            color[v] = 0;  // Backtrack if the color doesn't lead to a solution
        }
    }

    return 0;  // If no color can be assigned, return false
}

void printSolution() {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

int main() {
    // Initialize all vertices with no color (0 means no color assigned)
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Start graph coloring from vertex 0
    if (graphColoring(0)) {
        printSolution();  // Print the solution if found
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}
