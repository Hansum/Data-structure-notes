#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

typedef struct node{
  char data;
  struct node *link;
}ctype, *LinkStack;

/* Function prototypes */
void push(LinkStack * L, char elem);
void pop(LinkStack *L);
char top(LinkStack L);
void display(LinkStack L);

int main() {
	LinkStack A = NULL;
	int i;
	char word[] = {'P', 'R', 'O','G','R','A','M','M','I','N','G'};
	char first;
	
	for (i = 0; i < SIZE; i++) {
		push(&A, word[i]);
	}
	
	printf("Elements: \n");
	display(A);
	
	printf("\n\nAfter popping or deleting the first character:\n\n");
	pop(&A);
	display(A);
	
	printf("\n\nDisplaying the first/Top character after popping:\n");
	first = top(A);
	
	display(A);
	printf("\n\nTop Element: %c\n", first);
	
	return 0;
}

/* Inserting each element in the stack */
void push(LinkStack *L, char elem) {
	LinkStack temp;
	temp = (LinkStack)malloc(sizeof(ctype));
	
	if (temp != NULL) {
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}

}

/* Removing/Deleting the top most element in the stack */
void pop(LinkStack *L) {
	LinkStack temp;
	
	temp = *L;
	*L = temp->link;
	free(temp);
}

/* Returning the top element of the array */
char top(LinkStack L) {
	char value;
	
	value = L->data;
	
	return value;
}

/**
	Displaying the element in the stack
	
	Note: Since this is a stack, we dont necessarily need to traverse that why the element is displayed interchanged/Reverse

**/
void display(LinkStack L) {
	LinkStack trav;
	
	
	for (trav = L; trav != NULL; trav = trav->link) {
		printf("%c", trav->data);
	}
}


