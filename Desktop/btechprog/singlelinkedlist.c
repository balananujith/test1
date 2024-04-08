#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
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
                displayLinkedList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Freeing the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}

/*OUTPUT
1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 1
Enter data to insert at the beginning: 5

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 1
Enter data to insert at the beginning: 10

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 3
Linked list: 10 -> 5 -> NULL

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 2
Enter data to insert at the end: 15

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 3
Linked list: 10 -> 5 -> 15 -> NULL

1. Insert at Beginning
2. Insert at End
3. Display
4. Exit
Enter your choice: 4
Exiting...
*/