#include <stdio.h>

/*
 * Title: 90-Degree Counterclockwise Matrix Rotation
 * Description:
 * This program rotates a square matrix by 90 degrees counterclockwise.
 * The rotation is achieved in two steps:
 * 1. **Transpose the matrix** – Convert rows into columns.
 * 2. **Reverse the rows** – Flip the matrix upside down.
 * 
 * Steps:
 * - Transposition swaps a[i][j] with a[j][i] to convert rows into columns.
 * - Reversing the rows swaps top and bottom elements within each column.
 */

int main () {
    int a [4][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 10},
        {11, 12, 13, 14}
    };

    int row = 4;
    int col = 4;

    // Step 1: Transpose the matrix (swap a[i][j] with a[j][i])
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) { // Start from i+1 to avoid re-swapping
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Step 2: Reverse the rows (swap top and bottom elements within each column)
    for (int j = 0; j < col; j++) { 
        for (int i = 0; i < row / 2; i++) { // Swap first half with second half
            int temp = a[i][j];
            a[i][j] = a[row - 1 - i][j]; // Swap top with bottom
            a[row - 1 - i][j] = temp;
        }
    }

    // Print the rotated matrix
    printf("Matrix at 90-degrees (Counter Clockwise):\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
