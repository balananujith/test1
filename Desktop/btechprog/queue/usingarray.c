#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = data;
    printf("Enqueued %d into the queue.\n", data);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    int choice, data;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue into the queue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                printf("Dequeued %d from the queue.\n", dequeue(&queue));
                break;
            case 3:
                display(&queue);
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
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to enqueue into the queue: 5
Enqueued 5 into the queue.

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter data to enqueue into the queue: 10
Enqueued 10 into the queue.

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 5 10

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued 5 from the queue.

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting...
*/