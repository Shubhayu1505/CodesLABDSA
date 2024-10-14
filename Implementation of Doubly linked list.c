#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    // If the node to be deleted is not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the node to be deleted is not the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to display the list from the beginning
void displayFromBeginning(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to display the list from the end
void displayFromEnd(struct Node* node) {
    // Traverse to the last node
    while (node != NULL && node->next != NULL) {
        node = node->next;
    }

    // Traverse the list backward
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

// Main function to test the doubly linked list implementation
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display from Beginning\n");
        printf("5. Display from End\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("List from beginning: ");
                displayFromBeginning(head);
                break;
            case 5:
                printf("List from end: ");
                displayFromEnd(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
