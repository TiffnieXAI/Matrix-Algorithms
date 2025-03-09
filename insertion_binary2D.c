#include <stdio.h>
void checkLoop (int *n, int *nCheck); //Function for get input loop if invalid input 
void tryAgain (int *getTry, int *tCheck); //Function for trying the whole program again

int main() {
    int getTry, tCheck;
    do {
		
		//1 Input: Row, Column, Key
		int row, rCheck, col, cCheck, key, kCheck;
		printf("Input Row: ");
		rCheck = scanf("%d", &row);
		checkLoop (&row, &rCheck);
		
		printf("Input Column: ");
		cCheck = scanf("%d", &col);
		checkLoop (&col, &cCheck);
		
		printf("Input key (target element for search): ");
		kCheck = scanf("%D", &key);
		checkLoop (&key, &kCheck);
		
		
		
		
		//2 Input: Array elements, Flatten 1D array
		int a[row][col],aCheck;
		int size = row * col, tempA[size], tempIn = 0;
		printf("Input array elements.\n");
		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++) {
				printf("a[%d][%d]: ", i, j);
				aCheck = scanf("%d", &a[i][j]);
				while (aCheck != 1) {
					while (getchar() != '\n');
					printf("Invalid element! Input again: ");
					aCheck = scanf("%d", &a[i][j]);
				}
				
				tempA[tempIn++] = a[i][j];
			}
	
			
		
		//Processing 1 |Insertion Sort
		for (int i = 0; i < size; i++) {
			int tempKey = tempA[i];
			int j = i - 1;
			
			while (j >= 0 && tempA[j] > tempKey){
				tempA[j + 1] = tempA[j];
				j--;
			}
			
			tempA[j + 1] = tempKey;
		}
		
		
		
		//Processing 2 | Restructure into 2D
		tempIn = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				a[i][j] = tempA[tempIn++];
			}
		
		
		
			
		//processing 3 | Searching Algorithm: Binary Search
		int left = 0, right = row * col - 1, found = 0; //initialize end and beginning of array in 1D mapping
		
		while (left <= right) {
			//mid calculation (1D Mapping)
			int mid = left + (right - left)/2;
			
			//midValue calculation for 2D 
			int midValue = a[mid / col][mid % col]; //you will determine the value that the mid index has

			/*
			EXPLANATION NG MIDVALUE CALCULATION
			a[row][col]
			row = mid / col; || ex: our mid is 7, and our array is 4 x 4 this tells na "oh sa isang row 4 lang pwede kaya pag sumobra na sa apat at wala pa yung 7 kumabilang row ka na"
			col = mid % col || ex: mid still 7, this tells na "oh kapag nasa tamang row ka na yung number na to puntahan mo andon si 7"
			*/
			
			if (midValue == key) {
				printf("Target Found at a[%d][%d]!\n", mid / col, mid % col);
				found++;
				break;
			}
			
			else if (key > midValue){ // move to the right side of equation if your key is greater than midValue
				left = mid + 1;
			}
			
			else { //if lesser, move to left side
				right = mid - 1;
			}
	}
	
		if (found == 0) //if in any case the key value is not there
			printf("Target Not Found!\n");
			
		
		
		
		// Output 1 | Printing Sorted 2D Array with Borders
		printf("\nSorted 2D Array:\n");

		for (int i = 0; i < row; i++) {
    		// Print top border
    			for (int j = 0; j < col; j++) {
        			printf("+------");
    			}
   			 printf("+\n");

    		// Print row values with vertical bars
    			for (int j = 0; j < col; j++) {
        			printf("| %4d ", a[i][j]); // %2d ensures numbers align properly
    			}
    			printf("|\n");
		}

		// Print bottom border
		for (int j = 0; j < col; j++) {
   		 printf("+------");
		}
		printf("+\n");
		
		
		tryAgain (&getTry, &tCheck);
    } while (getTry != 0);
}

void checkLoop (int *n, int *nCheck) {
	while (*nCheck != 1){
		while (getchar() != '\n');
		printf("Number(s) only! Input again: ");
		*nCheck = scanf("%d", n);
	}
}

void tryAgain (int *getTry, int *tCheck) {
	printf("\n\n\nDo you want to try again?\n 0 - no | 1 - yes: ");
	*tCheck = scanf("%d", getTry);
	while (*tCheck != 1 || *getTry > 1 || *getTry < 0) {
		while (getchar() != '\n');
		printf("0 or 1 only!Input again: ");
		*tCheck = scanf("%d", getTry);
	}
	
	
	if (*getTry == 0) {
		printf("Exit Program? This can't be undone\n0 - yes | 1 - no: ");
			*tCheck = scanf("%d", getTry);
		while (*tCheck != 1 || *getTry > 1 || getTry < 0) {
			while (getchar() != '\n');
			printf("0 or 1 only!Input again: ");
			*tCheck = scanf("%d", getTry);
		}
		if (*getTry == 0)
			printf("Thank you for trying the program!\n");
			
		else 
			printf("Program restart...\n\n\n\n");
	}
	
	else 
			printf("Program restart...\n\n\n\n");
}
