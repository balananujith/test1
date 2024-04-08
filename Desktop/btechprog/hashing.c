#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int data) {
    int index = hashFunction(data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node *temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void search(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at bucket %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", key);
}

void delete(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Element %d deleted from bucket %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element %d not found for deletion\n", key);
}

int main() {
    initHashTable();
    int data, key, choice;

    do {
        printf("\n1. Insert Element\n");
        printf("2. Display Hash Table\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Hash Table:\n");
                display();
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
/*OUTPUT
1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 1
Enter data to insert: 5

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 1
Enter data to insert: 15

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 1
Enter data to insert: 25

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 2
Hash Table:
Bucket 0: NULL
Bucket 1: NULL
Bucket 2: 25 -> NULL
Bucket 3: NULL
Bucket 4: NULL
Bucket 5: 5 -> 15 -> NULL
Bucket 6: NULL
Bucket 7: NULL
Bucket 8: NULL
Bucket 9: NULL

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 3
Enter element to search: 15
Element 15 found at bucket 5

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 4
Enter element to delete: 5
Element 5 deleted from bucket 5

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 2
Hash Table:
Bucket 0: NULL
Bucket 1: NULL
Bucket 2: 25 -> NULL
Bucket 3: NULL
Bucket 4: NULL
Bucket 5: 15 -> NULL
Bucket 6: NULL
Bucket 7: NULL
Bucket 8: NULL
Bucket 9: NULL

1. Insert Element
2. Display Hash Table
3. Search Element
4. Delete Element
5. Exit
Enter your choice: 5
Exiting...
*/