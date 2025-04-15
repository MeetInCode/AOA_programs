
#include <stdio.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

// Find parent without recursion
int findParent(int parent[], int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;
}

// Union operation
void unionVertices(int parent[], int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    parent[rootU] = rootV;
}

// Sort edges based on weight (selection sort)
void sortEdges(int edges[][3], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (edges[j][2] < edges[min][2])
            {
                min = j;
            }
        }
        for (int k = 0; k < 3; k++)
        {
            int temp = edges[i][k];
            edges[i][k] = edges[min][k];
            edges[min][k] = temp;
        }
    }
}

void kruskal(int edges[][3], int edgeCount, int vertexCount)
{
    int parent[MAX_VERTICES];

    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = i;
    }

    int mstEdges = 0;

    printf("Edge : Weight\n");

    for (int i = 0; i < edgeCount && mstEdges < vertexCount - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV)
        {
            printf("%d - %d : %d\n", u + 1, v + 1, weight);
            unionVertices(parent, u, v);
            mstEdges++;
        }
    }
}

int main()
{
    int vertices = 7;
    int edgeCount = 9;

    int edges[MAX_EDGES][3] = {
        {0, 1, 28},
        {0, 5, 10},
        {1, 2, 16},
        {1, 6, 14},
        {2, 3, 12},
        {3, 4, 22},
        {3, 6, 18},
        {4, 5, 25},
        {4, 6, 24}};

    sortEdges(edges, edgeCount);
    kruskal(edges, edgeCount, vertices);

    return 0;
}