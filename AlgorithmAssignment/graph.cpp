#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <fstream>
#include <iostream>

#define INF INT_MAX
using namespace std;

// For Prim's algorithm part
// 1. Extract-Min function name : heapExtractMin
// 2. Min-Heapify function name : minHeapify
// 3. Decrease-Key function name : heapDecreaseKey
// 4. Insertion function name : minHeapInsert
// 5. Prim's algorithm function name : primMST

typedef struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int V;
    Edge** adj;
} Graph;

typedef struct MinHeapNode {
    int v;
    int key;
} MinHeapNode;

typedef struct MinHeap {
    MinHeapNode* heapArr;
    int* pos;
    int capacity;
    int size;
} MinHeap;

// Graph Initialization : Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Edge**)malloc(V * sizeof(Edge*));
    for (int i = 0; i < V; ++i) {
        graph->adj[i] = NULL;
    }
    return graph;
}

// Create a new edge with given vertex and weight
Edge* createEdge(int vertex, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->vertex = vertex;
    edge->weight = weight;
    return edge;
}

// Create a min heap with given capacity
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->heapArr = (MinHeapNode*)malloc(capacity * sizeof(MinHeapNode));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    return minHeap;
}

// Swap two min heap nodes
void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree with root at given index
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heapArr[left].key < minHeap->heapArr[smallest].key)
        smallest = left;

    if (right < minHeap->size && minHeap->heapArr[right].key < minHeap->heapArr[smallest].key)
        smallest = right;

    if (smallest != idx) {
        minHeap->pos[minHeap->heapArr[smallest].v] = idx;
        minHeap->pos[minHeap->heapArr[idx].v] = smallest;
        swapMinHeapNode(&minHeap->heapArr[smallest], &minHeap->heapArr[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the min heap is empty
int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Extract the minimum node from the min heap
MinHeapNode heapExtractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return (MinHeapNode){-1, -1};

    MinHeapNode root = minHeap->heapArr[0];
    MinHeapNode lastNode = minHeap->heapArr[minHeap->size - 1];
    minHeap->heapArr[0] = lastNode;

    minHeap->pos[root.v] = minHeap->size - 1;
    minHeap->pos[lastNode.v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Decrease the key value of a given vertex
void heapDecreaseKey(MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->heapArr[i].key = key;

    // Comparing node with parent
    while (i && minHeap->heapArr[i].key < minHeap->heapArr[(i - 1) / 2].key) {
        minHeap->pos[minHeap->heapArr[i].v] = (i - 1) / 2;
        minHeap->pos[minHeap->heapArr[(i - 1) / 2].v] = i;
        swapMinHeapNode(&minHeap->heapArr[i], &minHeap->heapArr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if a given vertex is in the min heap
int isInMinHeap(MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}

// Print the constructed MST stored in parent[]
void printMST(int parent[], int V, ofstream& output_file) {
    for (int i = 0; i < V; ++i) {
        output_file << i << " ";
        if (parent[i] == -1)
            output_file << "NIL\n";
        else {
            output_file << parent[i];
            if(i!=V-1) {
                output_file << "\n";
            }
        }
    }
}

// Insert key on the heap
void minHeapInsert(MinHeap* minHeap, int key) {
    // Increase heap size
    minHeap->size = minHeap->size + 1;
    // Assign a value smaller than any other key to the new element
    minHeap->heapArr[minHeap->size - 1].key = INT_MIN;
    // Decrease the key value to the desired value
    heapDecreaseKey(minHeap, minHeap->size - 1, key);
}

// Implementing Prim's algorithm for MST
void primMST(Graph* graph, ofstream& output_file) {
    int V = graph->V;
    int key[V];
    int parent[V];
    MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices.
    for (int v = 0; v < V; ++v) {
        parent[v] = -1;
        key[v] = INF;
        minHeap->heapArr[v] = (MinHeapNode){v, key[v]};
        minHeap->pos[v] = v;
    }

    key[0] = 0;

    for (int v = 0; v < V; ++v) {
        minHeapInsert(minHeap, key[v]);
    }

    // Loop to extract the minimum node from the min heap and update the
    // key value of adjacent vertices
    while (!isEmpty(minHeap)) {
        MinHeapNode minHeapNode = heapExtractMin(minHeap);
        int u = minHeapNode.v;

        for (Edge* temp = graph->adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (isInMinHeap(minHeap, v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                heapDecreaseKey(minHeap, v, key[v]);
            }
        }
    }

    // Print the constructed MST
    printMST(parent, V, output_file);
}

// Add an edge to the graph
void addEdge(Graph* graph, int u, int v, int weight) {
    Edge* edge = createEdge(v, weight);
    edge->next = graph->adj[u];
    graph->adj[u] = edge;

    edge = createEdge(u, weight);
    edge->next = graph->adj[v];
    graph->adj[v] = edge;
}

// For Floyd-Warshall algorithm part
// 1. Initialziation function name : initialize
// 2. Floyd-Warshall function name : floydWarshall

#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES][MAX_VERTICES];
int pred[MAX_VERTICES][MAX_VERTICES];
int num_vertices;

// Initialization for Floyd-Warshall algorithm
void initialize() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j) {
                dist[i][j] = 0;
                pred[i][j] = -1;
            } else {
                dist[i][j] = graph[i][j];
                pred[i][j] = (graph[i][j] != INF) ? i : -1;
            }
        }
    }
}

// Implementing Floyd-Warshall algorithm with distance and predecessor
void floydWarshall() {
    for (int k = 0; k < num_vertices; k++) {
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

// Print output of Floyd-Warshall algorithm result
void printOutput(ofstream& output_file) {
    output_file << "D " << num_vertices << "\n";
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (dist[i][j] == INF) {
                output_file << "INF ";
            } else {
                output_file << dist[i][j] << " ";
            }
        }
        output_file << "\n";
    }

    output_file << "P " << num_vertices << "\n";
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (pred[i][j] == -1) {
                output_file << "NIL ";
            } else {
                output_file << pred[i][j] + 1 << " ";
            }
        }
        if(i!=num_vertices-1) {
            output_file << "\n";
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream input_file_sp(argv[1]);
    ifstream input_file_mst(argv[2]);
    ofstream output_file_sp(argv[3]);
    ofstream output_file_mst(argv[4]);

    if (!input_file_sp.is_open() || !input_file_mst.is_open() || !output_file_sp.is_open() || !output_file_mst.is_open()) {
        cout << "Cannot open the file" << endl;
        return 1;
    }

    // Floyd-Warshall Algorithm part
    input_file_sp >> num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        char input[20];
        for (int j = 0; j < num_vertices; j++) {
            input_file_sp >> input;
            if (strcmp(input, "INF") == 0) {
                graph[i][j] = INF;
            } else {
                graph[i][j] = atoi(input);
            }
        }
    }

    initialize();
    floydWarshall();
    printOutput(output_file_sp);

    // Prim's Algorithm part
    int V, E, startVertex;
    input_file_mst >> V >> E >> startVertex;

    Graph* graph = createGraph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        input_file_mst >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    primMST(graph, output_file_mst);

    // resource deallocation
    input_file_sp.close();
    input_file_mst.close();
    output_file_sp.close();
    output_file_mst.close();

    return 0;
}
