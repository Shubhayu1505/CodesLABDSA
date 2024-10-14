#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum degree of the B-tree (2t-1 keys per node)

// A B-tree node
struct BTreeNode {
    int keys[MAX];               // Array of keys
    int count;                   // Current number of keys
    struct BTreeNode *children[MAX + 1];  // Array of child pointers
    int leaf;                    // 1 if leaf, 0 if internal node
};

// Function to create a new B-tree node
struct BTreeNode *createNode(int leaf) {
    struct BTreeNode *node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->count = 0;  // Initialize the number of keys in the node
    for (int i = 0; i < MAX + 1; i++) {
        node->children[i] = NULL;  // Initialize child pointers to NULL
    }
    return node;
}

// A utility function to traverse the B-tree
void traverse(struct BTreeNode *root) {
    if (root == NULL) {
        return;
    }

    // Traverse the tree
    int i;
    for (i = 0; i < root->count; i++) {
        if (!root->leaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }

    // Recursively traverse the last child
    if (!root->leaf) {
        traverse(root->children[i]);
    }
}

// A utility function to search a key in this tree
struct BTreeNode *search(struct BTreeNode *root, int key) {
    int i = 0;

    // Find the first key greater than or equal to the key
    while (i < root->count && key > root->keys[i]) {
        i++;
    }

    // If the found key is equal to the key, return this node
    if (i < root->count && key == root->keys[i]) {
        return root;
    }

    // If the key is not found here and this is a leaf node
    if (root->leaf) {
        return NULL;
    }

    // Go to the appropriate child
    return search(root->children[i], key);
}

// A utility function to split the child y of this node
// The child y must be full when this function is called
void splitChild(struct BTreeNode *parent, int i, struct BTreeNode *child) {
    // Create a new node to store (t-1) keys of y
    struct BTreeNode *newNode = createNode(child->leaf);
    newNode->count = MAX / 2;

    // Copy the last (t-1) keys of y to newNode
    for (int j = 0; j < MAX / 2; j++) {
        newNode->keys[j] = child->keys[j + MAX / 2 + 1];
    }

    // Copy the last t children of y to newNode
    if (!child->leaf) {
        for (int j = 0; j < MAX / 2 + 1; j++) {
            newNode->children[j] = child->children[j + MAX / 2 + 1];
        }
    }

    // Reduce the number of keys in y
    child->count = MAX / 2;

    // Insert a new child into the parent
    for (int j = parent->count; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    // Move a key from y to this node
    for (int j = parent->count - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[MAX / 2];
    parent->count++;
}

// A utility function to insert a new key in the B-tree node
// The node must be non-full when this function is called
void insertNonFull(struct BTreeNode *node, int key) {
    int i = node->count - 1;

    // If this is a leaf node
    if (node->leaf) {
        // Find the location of the new key and move all greater keys one place ahead
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        // Insert the new key at the found location
        node->keys[i + 1] = key;
        node->count++;
    }
    else {
        // Find the child that will have the new key
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // Check if the found child is full
        if (node->children[i]->count == MAX) {
            // Split the child if it's full
            splitChild(node, i, node->children[i]);

            // After the split, the middle key of node->children[i] goes up to node
            // and node->children[i] is split into two. Check which of the two
            // will have the new key
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// The main function to insert a new key in this B-tree
struct BTreeNode *insert(struct BTreeNode *root, int key) {
    // If the tree is empty
    if (root == NULL) {
        return createNode(1);  // Create the root node
    }

    // If the root is full, the tree grows in height
    if (root->count == MAX) {
        struct BTreeNode *newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);

        // Insert the key into the appropriate child of the new root
        insertNonFull(newRoot, key);
        return newRoot;
    }

    // Otherwise, insert the key in the non-full root
    insertNonFull(root, key);
    return root;
}

// --- Main Function ---
int main() {
    struct BTreeNode *root = NULL;
    int choice, key;

    while (1) {
        printf("\nB-tree Operations:\n");
        printf("1. Insert Key\n");
        printf("2. Traverse B-tree\n");
        printf("3. Search Key\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("B-tree Traversal: ");
                traverse(root);
                printf("\n");
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct BTreeNode *result = search(root, key);
                if (result != NULL) {
                    printf("Key %d found in the B-tree.\n", key);
                } else {
                    printf("Key %d not found in the B-tree.\n", key);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
