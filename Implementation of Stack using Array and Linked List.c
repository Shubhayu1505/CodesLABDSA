#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the stack

struct Stack {
    int array[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    stack->array[++(stack->top)] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from the stack.\n");
        return -1;
    }
    return stack->array[(stack->top)--];
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;
    initialize(&stack);
    
    int choice, data;
    
    while (1) {
        printf("\nArray-based Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
