/*
Description:
- This program sorts a predefined 2D array using Selection Sort.
- Only the **first pass** of Selection Sort is performed.
- The array is converted into a 1D array for sorting.
- After sorting, it is restructured back into a 2D array.
- The program prints the array **before and after** the first pass.
- The output is formatted with borders for better visualization.
*/

#include <stdio.h>

void printArray(int row, int col, int a[row][col]);

int main() {
    // Predefined 2D Array
    int row = 2, col = 5;
    int a[2][5] = {
        {3, 2, 1, 4, 5},
        {6, 0, 7, 9, 8}
    };

    // Convert to 1D array
    int size = row * col;
    int tempA[size], tempIn = 0;

    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) 
            tempA[tempIn++] = a[i][j];

    // Output: Original Array
    printf("Original Array:\n");
    printArray(row, col, a);

    // Selection Sort - First Pass Only
    int minIdx = 0;
    for (int j = 1; j < size; j++) {
        if (tempA[j] < tempA[minIdx])
            minIdx = j;
    }

    // Swap first element with the minimum element found
    if (minIdx != 0) {
        int temp = tempA[0];
        tempA[0] = tempA[minIdx];
        tempA[minIdx] = temp;
    }

    // Restructure 1D array back to 2D
    tempIn = 0;
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) 
            a[i][j] = tempA[tempIn++];

    // Output: After First Pass
    printf("\nAfter First Pass:\n");
    printArray(row, col, a);

    return 0;
}

// Function to print array with border formatting
void printArray(int row, int col, int a[row][col]) {
    for (int i = 0; i < row; i++) {
        // Print top border
        for (int j = 0; j < col; j++) {
            printf("+------");
        }
        printf("+\n");

        // Print row values with vertical bars
        for (int j = 0; j < col; j++) {
            printf("| %4d ", a[i][j]);
        }
        printf("|\n");
    }

    // Print bottom border
    for (int j = 0; j < col; j++) {
        printf("+------");
    }
    printf("+\n");
}
