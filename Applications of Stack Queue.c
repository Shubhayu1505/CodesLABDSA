#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// --- Stack structure ---
struct Stack {
    int top;
    char arr[MAX_SIZE];
};

// Stack Operations
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// --- 1.1 Reverse a String using Stack ---
void reverseString() {
    struct Stack stack;
    stack.top = -1;
    char str[MAX_SIZE], rev[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Push all characters to stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }
    
    // Pop all characters and form reversed string
    int i = 0;
    while (!isEmpty(&stack)) {
        rev[i++] = pop(&stack);
    }
    rev[i] = '\0';
    
    printf("Reversed string: %s\n", rev);
}

// --- 1.2 Balanced Parentheses Check ---
int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

void balancedParentheses() {
    struct Stack stack;
    stack.top = -1;
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expr);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&stack, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), expr[i])) {
                printf("Unbalanced parentheses\n");
                return;
            }
        }
    }
    if (isEmpty(&stack)) {
        printf("Balanced parentheses\n");
    } else {
        printf("Unbalanced parentheses\n");
    }
}

// --- 1.3 Evaluate Postfix Expression ---
int evaluatePostfix(char* exp) {
    struct Stack stack;
    stack.top = -1;
    
    for (int i = 0; exp[i]; i++) {
        // If the character is a number, push it to the stack
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }
    return pop(&stack);
}

// --- Queue structure ---
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Queue Operations
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// --- 2.1 Print Binary Numbers from 1 to n using Queue ---
void printBinaryNumbers(int n) {
    struct Queue* queue = createQueue(MAX_SIZE);
    enqueue(queue, 1);
    
    while (n--) {
        int num = dequeue(queue);
        printf("%d ", num);
        enqueue(queue, num * 10);
        enqueue(queue, num * 10 + 1);
    }
    printf("\n");
    free(queue->array);
    free(queue);
}

// --- 2.2 Circular Tour of Petrol Pumps ---
struct PetrolPump {
    int petrol;
    int distance;
};

int circularTour(struct PetrolPump pumps[], int n) {
    int start = 0, end = 1;
    int curr_petrol = pumps[start].petrol - pumps[start].distance;

    while (start != end || curr_petrol < 0) {
        while (curr_petrol < 0 && start != end) {
            curr_petrol -= pumps[start].petrol - pumps[start].distance;
            start = (start + 1) % n;
            if (start == 0)
                return -1;
        }
        curr_petrol += pumps[end].petrol - pumps[end].distance;
        end = (end + 1) % n;
    }
    return start;
}

// Main Program with Application Menu
int main() {
    int choice;
    
    while (1) {
        printf("\nSelect an Application:\n");
        printf("1. Reverse a String using Stack\n");
        printf("2. Balanced Parentheses using Stack\n");
        printf("3. Evaluate Postfix Expression using Stack\n");
        printf("4. Print Binary Numbers using Queue\n");
        printf("5. Circular Tour of Petrol Pumps using Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                reverseString();
                break;
            case 2:
                balancedParentheses();
                break;
            case 3: {
                char exp[MAX_SIZE];
                printf("Enter postfix expression: ");
                scanf("%s", exp);
                printf("Postfix evaluation result: %d\n", evaluatePostfix(exp));
                break;
            }
            case 4: {
                int n;
                printf("Enter n to print binary numbers from 1 to n: ");
                scanf("%d", &n);
                printBinaryNumbers(n);
                break;
            }
            case 5: {
                int n;
                printf("Enter the number of petrol pumps: ");
                scanf("%d", &n);
                struct PetrolPump pumps[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter petrol and distance for pump %d: ", i + 1);
                    scanf("%d %d", &pumps[i].petrol, &pumps[i].distance);
                }
                int start = circularTour(pumps, n);
                if (start != -1) {
                    printf("Start at petrol pump %d\n", start + 1);
                } else {
                    printf("No solution exists.\n");
                }
                break;
            }
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
