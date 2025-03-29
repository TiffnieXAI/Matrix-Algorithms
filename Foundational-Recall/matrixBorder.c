/*
This program prints only the border elements of a square matrix. It checks whether the element is in the first row, last row, first column, or last column and prints it accordingly.
*/

#include <stdio.h>

int main() {
    // Define a 4x4 matrix
    int a[4][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 8},
        {9, 10, 11, 12}
    };

    int size = 4;

    // Iterate through each element in the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Print only the border elements
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                printf("%2d ", a[i][j]);
            } else {
                printf("   "); // Print spaces for inner elements
            }
        }
        printf("\n");
    }
}
