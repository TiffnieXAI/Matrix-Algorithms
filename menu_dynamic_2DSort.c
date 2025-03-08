#include <stdio.h>

/*
Program Description:
This program allows the user to input a 2D array and choose a sorting algorithm
(Insertion Sort, Selection Sort, or Bubble Sort) to sort the elements. The array 
is flattened into a 1D array to perform the sorting, and then the sorted 1D array 
is converted back into a 2D array.
The program will repeat until the user decides to exit.
*/

void insertion(int a[], int size);  // Insertion sort
void selection(int a[], int size);  // Selection sort
void bubble(int a[], int size);     // Bubble sort

int main() {
    int getTry;
    do {
        // User input: row, column
        int row, column;
        printf("Input row: ");
        scanf("%d", &row);

        printf("Input column: ");
        scanf("%d", &column);

        // Initialize array and flatten 2D array
        int a[row][column];
        int tempIn = 0, size = row * column;  // Temporary index for 1D array, size of 1D array
        int tempA[size];  // Temp array to store the flattened values

        // Input elements into 2D array and flatten it into a 1D array
        printf("Input the array elements.\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf("a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
                tempA[tempIn++] = a[i][j];  // Flatten the 2D array to 1D
            }
        }

        // Sorting algorithm menu
        int choice;
        printf("\nChoose a sorting algorithm:\n1-Insertion\n2-Selection\n3-Bubble\n\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insertion Sort
                insertion(tempA, size);
                break;

            case 2:  // Selection Sort
                selection(tempA, size);
                break;

            case 3:  // Bubble Sort
                bubble(tempA, size);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        // Reconstruct the sorted 1D array back to the 2D array
        tempIn = 0;  // Reset tempIn for reassigning values
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                a[i][j] = tempA[tempIn++];  // Fill 2D array with sorted elements
            }
        }

        // Print the sorted 2D array
        printf("\nThe sorted 2D array is:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf("%d ", a[i][j]);  // Print each element of the array
            }
            printf("\n");
        }

        // Ask user if they want to try again
        printf("\nDo you want to try again?\n0 - no | 1 - yes: ");
        scanf("%d", &getTry);
        if (getTry == 0) {
            printf("Terminate Program? This can't be undone.\n0 - yes | 1 - no: ");
            scanf("%d", &getTry);

            if (getTry == 0)
                printf("Thank you for trying out the program!\n");
            else
                printf("Program restart...\n\n\n");
        } else {
            printf("Program restart...\n\n\n");
        }

    } while (getTry != 0);

    return 0;
}

// Insertion Sort function
void insertion(int a[], int size) {
    // Starts at index 1, assumes the first element is sorted
    for (int i = 1; i < size; i++) {
        int key = a[i];  // The element to insert
        int j = i - 1;

        // Move elements of a[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];  // Shift the larger element to the right
            j--;  // Move to the previous index
        }

        a[j + 1] = key;  // Place the key at its correct position
    }
}

// Selection Sort function
void selection(int a[], int size) {
    // Traverse through all elements
    for (int i = 0; i < size - 1; i++) {
        int min = i;  // Assume the first element is the smallest

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < size; j++) {
            if (a[min] > a[j])
                min = j;  // Update the minimum element
        }

        // Swap if the minimum element is not the current element
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// Bubble Sort function
void bubble(int a[], int size) {
    // Run through the array multiple times
    for (int i = 0; i < size - 1; i++) {
        // Compare adjacent elements and swap if necessary
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;  // Swap the elements
            }
        }
    }
}
