#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50

//int main() {
//	int i,row, column;
//	
//	for (i = 0; i < 4; i++) {
//		
//	}
//}

int main() {
	char fword[MAX] = {'a','n','d','n','b'};
	char comp[MAX];
	int i;
	int j = 0;
	
	for (i = strlen(fword) - 1; i >= 0; i--) {
		fword[i] = tolower(fword[i]);
		comp[j] = fword[i];
		j++;
	}
//	for (i = 0; i < MAX; i++) {
//		printf("%c", comp[i]);
//	}
	if (strcmp(fword,comp) == 0) {
		printf("A palindrome");
	} else {
		printf("Not a palindrome");
	}


	return 0;
}
