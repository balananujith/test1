#include <stdio.h>

#define MAX_SIZE 100

// Function to create an array
int createArray(int arr[]) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    return n;
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
int insertElement(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array overflow! Cannot insert element.\n");
        return size;
    }
    
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return size;
    }
    
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    
    return size + 1;
}

// Function to delete an element from the array
int deleteElement(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array is empty! Cannot delete element.\n");
        return size;
    }
    
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size;
    }
    
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;
    
    do {
        printf("\n1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                size = createArray(arr);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                size = insertElement(arr, size, element, position);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = searchElement(arr, size, element);
                if (position != -1)
                    printf("Element found at position %d.\n", position);
                else
                    printf("Element not found.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
    
    return 0;
}

/*OUTPUT
1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 1
Enter the number of elements: 5
Enter the elements:
1
2
3
4
5

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 2
Array elements: 1 2 3 4 5 

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 3
Enter the element to insert: 10
Enter the position to insert: 2
Pushed 10 onto the stack.

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 2
Array elements: 1 2 10 3 4 5 

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 4
Enter the position to delete: 3

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 2
Array elements: 1 2 10 4 5 

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 5
Enter the element to search: 4
Element found at position 3.

1. Create Array
2. Display Array
3. Insert Element
4. Delete Element
5. Search Element
6. Exit
Enter your choice: 6
Exiting...
*/