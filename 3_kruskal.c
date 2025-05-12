#include <stdio.h>
#include <stdlib.h> // For qsort function

#define MAX_VERTICES 100

// Find parent without recursion
int findParent(int parent[], int vertex)
{
    // Keep moving up the parent chain until we find the root
    // The root is a node whose parent is itself
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;

    /*
     * Example of findParent operation:
     * If we have parent[] = {0,0,1,2,2}
     * findParent(4) would follow:
     *   parent[4] = 2
     *   parent[2] = 1
     *   parent[1] = 0
     *   parent[0] = 0 (root found)
     * So findParent(4) returns 0, meaning vertex 4 belongs to the set with root 0
     */
}

// Union operation
void unionVertices(int parent[], int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    parent[rootU] = rootV;

    /*
     * Example of unionVertices operation:
     *
     * Consider two sets represented by parent[] = {0,0,1,3,3}
     * Set 1: {0,1,2} with root 0
     * Set 2: {3,4} with root 3
     *
     * If we call unionVertices(1, 3):
     * 1. First, we find rootU = findParent(1) = 0
     * 2. Then, we find rootV = findParent(3) = 3
     * 3. Finally, we set parent[rootU] = rootV, so parent[0] = 3
     *
     * After union, parent[] = {3,0,1,3,3}
     * The two sets are merged into one: {0,1,2,3,4} with root 3

     */
}

// Comparison function for qsort
int compareEdges(const void *a, const void *b)
{
    int *edge1 = (int *)a;
    int *edge2 = (int *)b;

    // Compare based on the weight (index 2)
    return edge1[2] - edge2[2];
}

void kruskal(int edges[][3], int edgeCount, int vertexCount)
{
    int parent[MAX_VERTICES];

    // Initially, each vertex is in its own set (singleton set)
    // parent[i] = i means i is the root of its own set
    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = i;
    }

    // Sort edges using qsort
    qsort(edges, edgeCount, sizeof(edges[0]), compareEdges);

    int mstEdges = 0;

    printf("Edge : Weight\n");

    for (int i = 0; i < edgeCount && mstEdges < vertexCount - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If u and v are in different sets (have different roots)
        // we can add this edge without creating a cycle
        if (parentU != parentV)
        {
            printf("%d - %d : %d\n", u + 1, v + 1, weight);
            unionVertices(parent, u, v); // Merge the two sets
            mstEdges++;

            /*
             * This is the core of Kruskal's algorithm:
             * 1. We sort edges by weight (done above with qsort)
             * 2. For each edge, we check if its endpoints belong to different sets
             * 3. If they do, we add the edge to MST and merge the sets
             * 4. If they don't, adding the edge would create a cycle, so we skip it
             *
             * The disjoint sets (represented by parent[]) track connected components
             * As we add edges, these components merge until we have one spanning tree
             */
        }
    }
}

int main()
{
    int vertices = 7;
    int edgeCount = 9;

    //{source_vertex, destination_vertex, weight}
    //{0, 1, 28}  →  Edge from vertex 0 to vertex 1 with weight 28

    // Define edges directly with the exact size needed
    int edges[9][3] = {
        {0, 1, 28},
        {0, 5, 10},
        {1, 2, 16},
        {1, 6, 14},
        {2, 3, 12},
        {3, 4, 22},
        {3, 6, 18},
        {4, 5, 25},
        {4, 6, 24}};

    kruskal(edges, edgeCount, vertices);

    return 0;
}
