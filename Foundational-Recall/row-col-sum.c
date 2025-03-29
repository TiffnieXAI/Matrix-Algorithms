#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        int row = 0, col = 0; // Reset at the start of each row iteration
        for (int j = 0; j < 3; j++) {
            row += a[i][j];  // Summing row elements
            col += a[j][i];  // Summing column elements
        }
        printf("Row[%d] Sum: %d\n", i, row);
        printf("Col[%d] Sum: %d\n\n", i, col);
    }
}
