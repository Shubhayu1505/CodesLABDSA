#include <stdio.h>
#include <stdlib.h>

// Structure for the node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// --- Create a new node ---
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- Insert a node in the BST ---
struct Node* insertNode(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// --- In-order Traversal (Left-Root-Right) ---
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);  // Visit left subtree
        printf("%d ", root->data);     // Visit root
        inOrderTraversal(root->right); // Visit right subtree
    }
}

// --- Pre-order Traversal (Root-Left-Right) ---
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     // Visit root
        preOrderTraversal(root->left); // Visit left subtree
        preOrderTraversal(root->right);// Visit right subtree
    }
}

// --- Post-order Traversal (Left-Right-Root) ---
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // Visit left subtree
        postOrderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Visit root
    }
}

// --- Search a node in the BST ---
struct Node* searchNode(struct Node* root, int key) {
    // Base cases: root is null or the key is present at the root
    if (root == NULL || root->data == key) {
        return root;
    }
    // Key is greater than root's key
    if (key > root->data) {
        return searchNode(root->right, key);
    }
    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// --- Main Function ---
int main() {
    struct Node* root = NULL;
    int choice, value, key;
    
    while (1) {
        printf("\nBinary Search Tree (BST) Operations:\n");
        printf("1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
                
            case 2:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
                
            case 3:
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
                
            case 4:
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
                
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &key);
                struct Node* found = searchNode(root, key);
                if (found != NULL) {
                    printf("Node with value %d found in the BST.\n", found->data);
                } else {
                    printf("Node with value %d not found in the BST.\n", key);
                }
                break;
                
            case 6:
                exit(0);
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
