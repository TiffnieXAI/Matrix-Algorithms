/*
    Program Title  : Matrix Transpose with Bordered Output

    Program Description:
    This C program allows the user to input a 2D matrix (with user-defined rows and columns) 
    and then computes its transpose. The original and transposed matrices are displayed 
    in a neatly formatted, bordered table for better readability.

    Features:
    - User inputs the number of rows and columns.
    - Validates inputs to ensure only integers are entered.
    - Accepts user input for matrix elements.
    - Displays both the original and transposed matrices with borders.
    - Uses a function to handle input validation.

    Constraints:
    - The program does not limit the size of the matrix but relies on VLAs (Variable-Length Arrays).
    - Input must be valid integers.
*/

#include <stdio.h>

void checkErr(int *num, int *check);

int main() {
    // INPUT 1: row, col
    int row, rCheck, col, cCheck;
    printf("Input row: ");
    rCheck = scanf("%d", &row);
    while (rCheck != 1) {
        checkErr(&row, &rCheck);
    }

    printf("Input column: ");
    cCheck = scanf("%d", &col);
    while (cCheck != 1) {
        checkErr(&col, &cCheck);
    }

    // INPUT 2: Array elements
    int a[row][col], aCheck;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("a[%d][%d]: ", i, j);
            aCheck = scanf("%d", &a[i][j]);
            while (aCheck != 1) {
                checkErr(&a[i][j], &aCheck);
            }
        }
    }

    // PRINT ORIGINAL MATRIX WITH BORDERS
    printf("\nOriginal Matrix:\n");
    printf("+");
    for (int i = 0; i < col; i++) printf("----");
    printf("+\n");

    for (int i = 0; i < row; i++) {
        printf("|");
        for (int j = 0; j < col; j++) {
            printf("%3d ", a[i][j]); // Align numbers
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < col; i++) printf("----");
    printf("+\n");

    // PRINT TRANSPOSED MATRIX WITH BORDERS
    printf("\nTransposed Matrix:\n");

    printf("+");
    for (int i = 0; i < row; i++) printf("----");
    printf("+\n");

    for (int i = 0; i < col; i++) {
        printf("|");
        for (int j = 0; j < row; j++) {
            printf("%3d ", a[j][i]);
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < row; i++) printf("----");
    printf("+\n");

    return 0;
}

// INPUT VALIDATION FUNCTION
void checkErr(int *num, int *check) {
    while (getchar() != '\n');  // Clear input buffer
    printf("Number(s) only! Input again: ");
    *check = scanf("%d", num);
}
