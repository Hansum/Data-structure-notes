#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef struct node{
	int data;
	struct node *link;
}SET;

int unionsort(SET A, SET B);
void init(SET *L);
void insertFirst(SET *I,int elem);
void display(SET X);

int main()
{
	SET A,B,C;
	init(&A);
	init(&B);
	insertFirst(&A,1);
	insertFirst(&A,0);
	insertFirst(&A,0);
	insertFirst(&A,1);
	insertFirst(&A,1);
	insertFirst(&A,0);
	
	insertFirst(&B,0);
	insertFirst(&B,1);
	insertFirst(&B,0);
	insertFirst(&B,0);
	insertFirst(&B,1);
	insertFirst(&B,1);
	C = unionsort(A,B);
	display(C);
}
void init(SET *L)
{
	*L = NULL;
}
void insertFirst(SET *L,int elem)
{
	SET temp;
	temp = (SET)malloc(sizeof(struct node));
	if(temp!=NULL)
	{
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}
}
int unionsort(SET A, SET B)
{
	SET C, temp, trav;
	for(trav = A;trav!=NULL;trav = trav->link)
	{
		C = (SET)malloc(sizeof(ctype));
		for(temp = B;temp!NULL;temp = temp->link)
		{
			if(trav->data == 1 || temp->data == 1)
			{
				C->data = 1
			}else{
				C->data = 0
			}
		}
		return C;
	}
}
void display(SET X)
{
	SET trav;
	for(trav = X;trav!=NULL;trav= trav->link)
	{
		printf("C: %d",trav->data);
	}
}
