#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  char data;
  struct node *link;
}ctype, *LinkStack;

void push(LinkStack * L, char elem);
void pop(LinkStack *L);
char top(LinkStack L);
void display(LinkStack L);

int main() {
	LinkStack A;
	int i;
	char letters[] = {'P', 'I', 'A'};
	char first;
	
	for (i = 0; i < 3; i++) {
		push(&A, letters[i]);
	}
	
	pop(&A);
	first = top(A);
	
	display(A);
	printf("Top Element: %c", first);
	
	return 0;
}

void push(LinkStack * L, char elem) {
	LinkStack temp;
	temp = (LinkStack)malloc(sizeof(ctype));
	
	if (temp != NULL) {
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}
}

void pop(LinkStack *L) {
	LinkStack temp;
	
	temp = *L;
	*L = temp->link;
	free(temp);
}

char top(LinkStack L) {
	char elem;
	elem = L->data;
	
	return elem;
}

void display(LinkStack L) {
	LinkStack trav;
	
	printf("Elements: \n");
	for (trav = L; trav != NULL; trav = trav->link) {
		printf("%c\n", trav->data);
	}
}


