#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10  // Maximum number of vertices in the graph

// Adjacency matrix for the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize the adjacency matrix
void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  // Set all values to 0 (no edges)
        }
    }
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;  // Mark the edge from vertex u to vertex v
    adjMatrix[v][u] = 1;  // For an undirected graph, mark v to u as well
}

// Function to delete an edge from the graph
void deleteEdge(int u, int v) {
    adjMatrix[u][v] = 0;  // Remove the edge from u to v
    adjMatrix[v][u] = 0;  // Remove the edge from v to u for an undirected graph
}

// Function to display the adjacency matrix
void displayGraph(int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int vertices, choice, u, v;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    if (vertices > MAX_VERTICES) {
        printf("Number of vertices exceeds the limit of %d.\n", MAX_VERTICES);
        return -1;
    }

    initializeGraph(vertices);  // Initialize the graph

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the vertices to add an edge (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                    addEdge(u, v);
                } else {
                    printf("Invalid vertices!\n");
                }
                break;

            case 2:
                printf("Enter the vertices to delete an edge (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                    deleteEdge(u, v);
                } else {
                    printf("Invalid vertices!\n");
                }
                break;

            case 3:
                displayGraph(vertices);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
