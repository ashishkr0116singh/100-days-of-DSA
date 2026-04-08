#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list representation
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// stack for storing topological order
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void dfs(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }

    // push to stack after visiting all neighbors
    push(vertex);
}

void topologicalSort(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            dfs(graph, i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}
