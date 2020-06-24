#include <stdio.h>
#include <conio.h>

int main() {
	int space, stars,row, TotalNumberOfRows = 5;
	
	for(row = 1; row <= TotalNumberOfRows; row++) { // row
		for (space = 1; space <= (TotalNumberOfRows - row); space++) {
			printf(" ");
		}
		for (stars = 1; stars <= ((2*row) - 1); stars++) {
			printf("* ");
		}
		printf("\n");
	}
	
	return 0;
}


//int main () {
//	int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14};
//	printf("size of array: %lu", sizeof(arr[0]));
//	return 0;
//}
