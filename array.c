#include <stdio.h>

int arr[100];
int size = 0;

// --------- Insert Element ----------
void insertElement() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    arr[size++] = val;
    printf("Inserted %d at index %d\n", val, size - 1);
}

// --------- Delete Element ----------
void deleteElement() {
    int index, i;
    if (size == 0) {
        printf("Array is empty. Nothing to delete!\n");
        return;
    }
    printf("Enter index to delete (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index!\n");
        return;
    }
    printf("Deleting element %d at index %d\n", arr[index], index);
    for (i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
}

// --------- Search Element ----------
void searchElement() {
    int val, i, found = 0;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            printf("Value %d found at index %d\n", val, i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Value %d not found in array.\n", val);
}

// --------- Display Array ----------
void displayArray() {
    int i;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// --------- Main Menu ----------
int main() {
    int choice;
    while (1) {
        printf("\n---- ARRAY SIMULATION ----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertElement();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            searchElement();
            break;
        case 4:
            displayArray();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}