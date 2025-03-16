#include <stdio.h>


#define ROWS 5
#define COL 5


int main () {
  int a[][COL] = {{2, 2, 4, 3, 5}, {5, 2, 9, 7, 5}, {4, 3, 2, 4, 2}, {3, 2, 1, 4, 7}, {7, 8, 2, 1, 9}};


  //INPUT 1: search element
  int search, sCheck;
  printf("Input search: ");
  sCheck = scanf("%d", &search);
  while (sCheck != 1) {
    while (getchar() != '\n');
    printf("Number(s) only! Input again: ");
    sCheck = scanf("%d", &search);
  }

  //OUTPUT 1: Print the diagonal
  printf("\nLeft Diagonal:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COL; j++) {
      if (i == j) {
        printf("%d ", a[i][j]);
      }

      else
       printf(" ");
    }
    printf("\n");
  }



  //OUTPUT 2: Print the diagonal
  printf("\nRight Diagonal:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COL; j++) {
        if (j == (COL - 1 - i)) {
            printf("%d", a[i][j]); // Print the diagonal element
        } else {
            printf(" "); // Print spaces to align the diagonal
        }
    }
    printf("\n"); // Move to the next row
}



  int found = 0;
  //PROCESS 1: search array
  printf("\n-------------------\n");
  printf("| key | row | col |\n");
  printf("-------------------\n");

  for (int i = 0; i < ROWS; i++) {
    // Checking the main diag (Left Diagonal)
    // The condition (i == i) means the row index and column index are equal, kasi if u visualize, the ones with equal row and index yung nasa diagonal na to
    if (a[i][i] == search) {
        printf("| %3d | %3d | %3d |\n", a[i][i], i, i);
        found++;
    }

    // Checking the secondary diag (Right Diagonal)
    // The formula (ROWS - 1 - i) calculates the column index for the secondary diagonal.
    // This works kasi example, in a 3x3 matrix, ito yung diagonals:
    //   - row 0 → column 2
    //   - row 1 → column 1
    //   - row 2 → column 0
    else if (a[i][(ROWS - 1) - i] == search) {
        printf("| %3d | %3d | %3d |\n", a[i][ROWS - 1 - i], i, ROWS - 1 - i);
        found++;
    }


  if (!found) {
    printf("| Value Not found |\n");
}

  else
   printf("Value found successfully!\n");
}


