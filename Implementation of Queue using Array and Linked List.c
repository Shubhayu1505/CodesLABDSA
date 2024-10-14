#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the queue

struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot enqueue %d.\n", data);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = data;
    printf("Enqueued: %d\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    int dequeued = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;  // Reset the queue if it's empty
    } else {
        queue->front++;
    }
    return dequeued;
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, data;

    while (1) {
        printf("\nArray-based Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
