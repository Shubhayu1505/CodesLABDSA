#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Array to store tree elements
int tree[MAX_SIZE];
int size = 0;  // To track the number of elements in the tree

// --- Insert node in the tree ---
void insertNode(int data) {
    if (size >= MAX_SIZE) {
        printf("Tree is full!\n");
        return;
    }
    tree[size] = data;
    size++;
}

// --- In-order Traversal (Left-Root-Right) ---
void inOrderTraversal(int index) {
    if (index >= size) {
        return;
    }
    inOrderTraversal(2 * index + 1);  // Visit left child
    printf("%d ", tree[index]);       // Visit root
    inOrderTraversal(2 * index + 2);  // Visit right child
}

// --- Pre-order Traversal (Root-Left-Right) ---
void preOrderTraversal(int index) {
    if (index >= size) {
        return;
    }
    printf("%d ", tree[index]);       // Visit root
    preOrderTraversal(2 * index + 1); // Visit left child
    preOrderTraversal(2 * index + 2); // Visit right child
}

// --- Post-order Traversal (Left-Right-Root) ---
void postOrderTraversal(int index) {
    if (index >= size) {
        return;
    }
    postOrderTraversal(2 * index + 1); // Visit left child
    postOrderTraversal(2 * index + 2); // Visit right child
    printf("%d ", tree[index]);        // Visit root
}

// --- Main function ---
int main() {
    int choice, data;

    while (1) {
        printf("\nBinary Tree using Array:\n");
        printf("1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;

            case 2:
                printf("In-order Traversal: ");
                inOrderTraversal(0);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preOrderTraversal(0);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postOrderTraversal(0);
                printf("\n");
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
