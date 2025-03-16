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
  printf("\nDiagonal:\n");
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



  int found = 0;
  //PROCESS 1: search array
  printf("\n-------------------\n");
  printf("| val | row | col |\n");
  printf("-------------------\n");
  for (int i = 0; i < ROWS; i++) {
    if (a[i][i] == search) {
      printf("| %3d | %3d | %3d |\n", a[i][i], i, i);
      found++;
    }
  }

  if (!found) {
    printf("| Value Not found |\n");
}
}

