#include <stdio.h>

/*
 Description:
 This program transposes a square matrix (3x3) by swapping elements across its main diagonal.
 The transposition converts rows into columns, effectively flipping the matrix along its diagonal.

 Key Learning:
 - When swapping elements in an array, you must avoid swapping elements twice.
   Similar to string reversal (where we swap only up to half the length),
   transposing a matrix requires careful traversal to prevent re-swapping.

 - In a square matrix, swapping happens between elements `a[i][j]` and `a[j][i]`.
   To avoid redundant swaps, we only traverse the **upper triangle** (above the diagonal).
   That’s why `j` starts from `i + 1`, ensuring that we don't swap elements back.

 🔥 TIP: Avoid swapping elements twice in any problem by:
   1. Identifying which elements need swapping and marking them.
   2. Ensuring your traversal does not revisit swapped elements.
   3. Using two-pointer techniques or constraints like `j = i + 1` (as done here).
*/

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int row = 3;
    int col = 3;

    // Transposing the matrix
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Printing the transposed matrix
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
