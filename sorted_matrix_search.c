#include <stdio.h>

// Program Name: 2D Array Binary Search
// Description: This program allows the user to input a 2D array,
// flattens it into a 1D array, sorts it using insertion sort,
// and then performs a binary search to find a target value.

void binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Found!\nIndex: arr[%d]\n", mid);
            return;
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Not Found!\n");
}

int main() {
    int row, col, target;
    char retry;

    do {
        // User Input: Row and Column with validation
        do {
            printf("Input Row (positive integer): ");
            if (scanf("%d", &row) != 1 || row <= 0) {
                printf("Invalid input! Please enter a positive integer.\n");
                while (getchar() != '\n'); // Clear input buffer
            } else break;
        } while (1);

        do {
            printf("Input Column (positive integer): ");
            if (scanf("%d", &col) != 1 || col <= 0) {
                printf("Invalid input! Please enter a positive integer.\n");
                while (getchar() != '\n'); // Clear input buffer
            } else break;
        } while (1);

        int a[row][col];
        int size = row * col;
        int arr[size], tempIn = 0;

        // User Input: Array Elements
        printf("Enter %d elements:\n", size);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("a[%d][%d]: ", i, j);
                while (scanf("%d", &a[i][j]) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n');
                    printf("a[%d][%d]: ", i, j);
                }
                arr[tempIn++] = a[i][j];
            }
        }

        // Sorting: Insertion Sort
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        // User Input: Target Number with validation
        do {
            printf("Input target: ");
            if (scanf("%d", &target) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                while (getchar() != '\n');
            } else break;
        } while (1);

        // Binary Search Execution
        binarySearch(arr, size, target);

        // Reconstruct sorted 2D array and locate target
        tempIn = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[i][j] = arr[tempIn++];
                if (a[i][j] == target) {
                    printf("Target found at a[%d][%d]\n", i, j);
                }
            }
        }

        // Display Sorted 2D Array
        printf("\nSorted 2D Array:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        // Retry Prompt
        printf("\nWould you like to retry? (y/n): ");
        scanf(" %c", &retry);
        while (getchar() != '\n'); // Clear buffer

    } while (retry == 'y' || retry == 'Y');

    printf("Program exited.\n");
    return 0;
}
