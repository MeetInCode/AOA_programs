#include <stdio.h>

#define V 4 // Number of vertices
#define M 3 // Number of available colors

char colors[M] = {'R', 'G', 'B'}; // Available colors
char vertexColor[V];              // Stores assigned color to each vertex

// Graph adjacency matrix
int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}};

// Check if it's safe to assign color to a vertex
int isSafe(int vertex, char colorValue)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] && vertexColor[i] == colorValue)
            return 0; // Not safe if adjacent vertex has same color
    }
    return 1; // Safe to assign
}

// Recursive function to color the graph
int graphColoring(int vertex)
{
    if (vertex == V)
        return 1; // All vertices are colored

    for (int i = 0; i < M; i++)
    {
        char colorValue = colors[i];
        if (isSafe(vertex, colorValue))
        {
            vertexColor[vertex] = colorValue;
            if (graphColoring(vertex + 1))
                return 1;
            vertexColor[vertex] = 0; // Backtrack
        }
    }

    return 0; // No valid color found
}

// Print the color assigned to each vertex
void printSolution()
{
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %c\n", i, vertexColor[i]);
}

int main()
{
    for (int i = 0; i < V; i++)
        vertexColor[i] = 0; // Initialize all colors to 0 (no color)

    if (graphColoring(0))
        printSolution();
    else
        printf("Solution does not exist.\n");

    return 0;
}
