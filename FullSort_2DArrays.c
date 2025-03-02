/*
Program: Sorting a 2D Matrix
Description: This program takes user input to define a 2D matrix, 
             fills it with integer values, sorts the elements using 
             selection sort, and then displays the sorted matrix.

*/

#include <stdio.h>

// Function to handle invalid input
void error(int *n, int *eCheck) {
    while (getchar() != '\n');
    printf("Invalid Input! Number(s) only: ");
    *eCheck = scanf("%d", n);
}

int main() {
    int getTry, tCheck;

    do {
        int row, rCheck;
        // User Input: Row Size
        printf("Input row: ");
        rCheck = scanf("%d", &row);
        while (rCheck != 1) {
            error(&row, &rCheck);
        }

        int col, cCheck;
        // User Input: Column Size
        printf("Input column: ");
        cCheck = scanf("%d", &col);
        while (cCheck != 1) {
            error(&col, &cCheck);
        }

        int a[row][col], aCheck;
        // User Input: Array Elements
        printf("Input Array Elements.\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("a[%d][%d]: ", i, j);
                aCheck = scanf("%d", &a[i][j]);
                while (aCheck != 1) {
                    while (getchar() != '\n');
                    printf("Number(s) Only! Input Again: ");
                    aCheck = scanf("%d", &a[i][j]);
                }
            }
        }

        int size = row * col;
        int array[size], temp = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                array[temp++] = a[i][j];
            }
        }

        // Sort: Selection Sort
        for (int i = 0; i < size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                if (array[min] > array[j]) {
                    min = j;
                }
            }
            // Swap
            if (min != i) {
                int tem = array[i];
                array[i] = array[min];
                array[min] = tem;
            }
        }
        
        temp = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[i][j] = array[temp++];
            }
        }

        // Display Sorted Matrix
        printf("Sorted Matrix:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        // Get Try, DO NOT TOUCH
        printf("The program is complete! Try Again?\n0 - no | 1 - yes: ");
        tCheck = scanf("%d", &getTry);
        // Error Checking
        while (tCheck != 1) {
            while (getchar() != '\n');
            printf("0 or 1 Only! Input Again: ");
            tCheck = scanf("%d", &getTry);
        }

        if (getTry == 0) {
            printf("End Program? This can't be undone.\n0 - yes | 1 - no: ");
            tCheck = scanf("%d", &getTry);
            // Error Checking
            while (tCheck != 1) {
                while (getchar() != '\n');
                printf("0 or 1 Only! Input Again: ");
                tCheck = scanf("%d", &getTry);
            }
            if (getTry == 0) {
                printf("Thank you for trying the program!\n");
            } else {
                printf("Program Runs Again!\n");
            }
        } else if (getTry == 1) {
            printf("Program Runs Again!\n");
        }
    } while (getTry != 0);
}
