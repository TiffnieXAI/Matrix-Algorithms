/*
This program prints only the diagonal elements of a square matrix. The condition j == i selects the primary diagonal, and j == size - 1 - i selects the secondary diagonal.
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
            // Print elements that are in the primary or secondary diagonal
            if (j == i || j == size - 1 - i) {
                printf("%2d ", a[i][j]);
            } else {
                printf("   "); // Print spaces for non-diagonal elements
            }
        }
        printf("\n");
    }
}

