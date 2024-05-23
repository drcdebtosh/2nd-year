/*
Prim's Algorithm

Input: Graph represented by an adjacency matrix graph[V][V], where V is the number of vertices.

Output: Minimum Spanning Tree represented by an array parent[].

1. Create an array key[] of size V and initialize all keys as INFINITE.
   Initialize an array parent[] of size V and set all values to -1.
   Choose the starting vertex as the first vertex or any arbitrary vertex.

2. Set key[starting_vertex] = 0, as the key of the starting vertex in the MST is always 0.

3. Repeat the following V times:
     a. Choose the vertex u with the minimum key value such that u is not yet included in the MST.
     b. Include u in the MST by setting parent[u] = selected vertex (the vertex with the minimum key value).
     c. Update the key values of all adjacent vertices of u.
        Update key[v] if v is not in the MST and the weight of edge u-v is less than key[v].

4. The array parent[] now represents the minimum spanning tree.

*/
#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    int mstSet[V]; // To represent set of vertices not yet included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

int main() {
    // Example graph represented using an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
