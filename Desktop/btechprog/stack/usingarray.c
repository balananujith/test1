#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = data;
    printf("Pushed %d onto the stack.\n", data);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
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
Enter data to push onto the stack: 10
Pushed 10 onto the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter data to push onto the stack: 20
Pushed 20 onto the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 20 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped 20 from the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting...
*/