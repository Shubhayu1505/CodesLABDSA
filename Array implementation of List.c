#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the list

// Structure for Array-based List
struct ArrayList {
    int array[MAX_SIZE];
    int size;
};

// Function to insert an element at a specified position
void insertElement(struct ArrayList* list, int data, int position) {
    if (list->size >= MAX_SIZE) {
        printf("List is full. Cannot insert new element.\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", list->size);
        return;
    }

    // Shift elements to the right to create space for the new element
    for (int i = list->size; i > position; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[position] = data;
    list->size++;
}

// Function to delete an element at a specified position
void deleteElement(struct ArrayList* list, int position) {
    if (list->size == 0) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= list->size) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", list->size - 1);
        return;
    }

    // Shift elements to the left to fill the gap of the deleted element
    for (int i = position; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
}

// Function to display the list
void displayList(struct ArrayList* list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

// Main function to test the array-based list implementation
int main() {
    struct ArrayList list;
    list.size = 0;  // Initialize the list size to 0

    int choice, data, position;

    while (1) {
        printf("\nArray-based List Operations:\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert (0 to %d): ", list.size);
                scanf("%d", &position);
                insertElement(&list, data, position);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", list.size - 1);
                scanf("%d", &position);
                deleteElement(&list, position);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
