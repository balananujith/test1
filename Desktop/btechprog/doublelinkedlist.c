#include <stdio.h>
#include <stdlib.h>

// Structure for a node in doubly linked list
struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
};

// Function to create a new node for doubly linked list
struct DoublyNode* createDoublyNode(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of doubly linked list
void insertAtBeginning(struct DoublyNode** headRef, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of doubly linked list
void insertAtEnd(struct DoublyNode** headRef, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct DoublyNode* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the doubly linked list
void displayDoublyLinkedList(struct DoublyNode* head) {
    struct DoublyNode* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the doubly linked list
void freeDoublyLinkedList(struct DoublyNode* head) {
    struct DoublyNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct DoublyNode* head = NULL;
    int choice, data;

    do {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                displayDoublyLinkedList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Freeing the memory allocated for the doubly linked list
    freeDoublyLinkedList(head);

    return 0;
}
/*OUTPUT
1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 1
Enter data to insert at the beginning: 30

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 1
Enter data to insert at the beginning: 20

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 2
Enter data to insert at the end: 40

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 2
Enter data to insert at the end: 50

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 3
Doubly linked list: 20 <-> 30 <-> 40 <-> 50 <-> NULL

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 4
Exiting...
*/