#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack *stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == NULL);
}

void push(struct Stack *stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, data;

    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push onto the stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                printf("Popped %d from the stack.\n", pop(&stack));
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
/*OUTPUT
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to push onto the stack: 5
Pushed 5 onto the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to push onto the stack: 10
Pushed 10 onto the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 5 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped 10 from the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 5 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting...
*/