#include <stdio.h>

/*
    Program: Pointer-based 2D Array Printing
    Description:
        - This program initializes a 3x3 matrix with predefined values.
        - It prints the matrix in a bordered format using pointers.
        - Uses pointer arithmetic instead of direct array indexing.
*/

int main() {
    // Declare and initialize a 3x3 matrix
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print top border
    for (int i = 0; i < 3; i++) {
        printf("+----");
    }
    printf("+\n");

    // Print matrix values with row separators
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %2d ", *(*(a + i) + j));  // Accessing elements using pointer notation
        }
        printf("|\n");  // End row

        // Print row separator
        for (int j = 0; j < 3; j++) {
            printf("+----");
        }
        printf("+\n");
    }

    return 0;
}
