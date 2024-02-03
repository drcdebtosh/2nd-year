/*DFS(graph, start_vertex, visited):
    1. Create an array 'visited' to keep track of visited vertices. Initialize all elements to 0.
    2. Create a stack to store vertices.
    3. Push the start_vertex onto the stack.
    4. Mark start_vertex as visited.
    5. Print or process start_vertex.
    6. While the stack is not empty:
        a. Pop a vertex from the stack.
        b. For each adjacent vertex of the popped vertex:
            i. If the adjacent vertex is not visited:
                - Push the adjacent vertex onto the stack.
                - Mark the adjacent vertex as visited.
                - Print or process the adjacent vertex.
    7. End

*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Depth-First Search function
void DFS(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Traverse all the adjacent vertices of the current vertex
    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    int* visited = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Depth-First Traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);

    free(graph);
    free(visited);

    return 0;
}
