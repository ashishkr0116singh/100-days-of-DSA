#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for adjacency list
struct List {
    struct Node* head;
};

// Structure for graph
struct Graph {
    int V;
    struct List* array;
};

// Create a new adjacency list node
struct Node* newNode(int vertex, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct List*)malloc(V * sizeof(struct List));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* node = newNode(dest, weight);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    // For undirected graph, add reverse edge
    node = newNode(src, weight);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

// Min-Heap node
struct HeapNode {
    int vertex;
    int dist;
};

// Min-Heap structure
struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct HeapNode** array;
};

// Create MinHeap node
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

// Create MinHeap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

// Swap two heap nodes
void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index
void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = heap->array[smallest];
        struct HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract minimum node
struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct HeapNode* root = heap->array[0];
    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    --heap->size;
    minHeapify(heap, 0);

    return root;
}

// Decrease distance value
void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if heap is empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra’s Algorithm
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newHeapNode(src, dist[src]);
    heap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);

    heap->size = V;

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        struct Node* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;
            if (heap->pos[v] < heap->size && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(heap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program
int main() {
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}
