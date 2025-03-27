#include <stdio.h>

/*
 * Title: 90-Degree Counterclockwise Rotation (Non-Square Matrix)
 * Description:
 * This program rotates a non-square matrix (MxN) by 90 degrees counterclockwise.
 * The process involves two main steps:
 * 1. **Transpose the matrix** - Swap rows and columns.
 * 2. **Reverse the order of columns** - Swap first and last rows in the new transposed matrix.
 */

int main() {
    int a[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int row = 4;
    int col = 3;

    int b[col][row]; // Transposed matrix (3x4)

    // Step 1: Transpose the matrix (swap a[i][j] → b[j][i])
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            b[i][j] = a[j][i];
        }
    }

    // Step 2: Reverse the order of columns (swap first and last rows of b)
    for (int i = 0; i < row / 2; i++) { // Reverse rows of transposed matrix
        for (int j = 0; j < col; j++) {
            int temp = b[j][i];
            b[j][i] = b[j][row - 1 - i];
            b[j][row - 1 - i] = temp;
        }
    }

    // Print the rotated matrix
    printf("Matrix at 90-degrees (Counter Clockwise):\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
