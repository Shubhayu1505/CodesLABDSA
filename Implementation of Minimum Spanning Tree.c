#include <stdio.h>
#include <limits.h>

#define MAX 100  // Maximum number of vertices

int graph[MAX][MAX];  // Adjacency matrix representation of the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print the MST using Prim's algorithm
void primMST(int vertices) {
    int parent[MAX];  // Array to store the MST
    int key[MAX];     // Key values used to pick the minimum weight edge
    int mstSet[MAX];  // Boolean array to represent the set of vertices included in the MST

    // Initialize all keys as infinite (INT_MAX) and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from the first vertex (index 0), so key[0] = 0
    key[0] = 0;
    parent[0] = -1;  // First node is always the root of the MST

    // The MST will have exactly 'vertices' vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, vertices);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update the key values and parent index of the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update key only if graph[u][v] is smaller than key[v] and v is not yet included in MST
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, vertices);
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call the Prim's algorithm to find and print the MST
    primMST(vertices);

    return 0;
}
