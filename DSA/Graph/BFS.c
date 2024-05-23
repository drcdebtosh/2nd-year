#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation for BFS
typedef struct {
    int front, rear;
    int arr[MAX_NODES];
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->arr[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = queue->arr[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    return value;
}

// Graph representation using adjacency matrix
typedef struct {
    int vertices;
    int **adjMatrix;
} Graph;

Graph createGraph(int vertices) {
    Graph graph;
    graph.vertices = vertices;

    // Allocate memory for adjacency matrix
    graph.adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph.adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph *graph, int start, int end) {
    // Assuming the graph is undirected
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void bfs(Graph *graph, int startNode) {
    Queue queue;
    initializeQueue(&queue);

    int visited[MAX_NODES] = {0};

    printf("BFS traversal starting from node %d: ", startNode);

    // Enqueue the starting node and mark it as visited
    enqueue(&queue, startNode);
    visited[startNode] = 1;

    while (!isQueueEmpty(&queue)) {
        int currentNode = dequeue(&queue);
        printf("%d ", currentNode);

        // Visit all adjacent nodes of the current node
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    Graph graph = createGraph(vertices);

    printf("Enter the edges (format: startNode endNode):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(&graph, start, end);
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    bfs(&graph, startNode);

    return 0;
}
