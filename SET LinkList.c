#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef struct cell{
	int elem;
	struct cell * link;
}ctype, *SET;

void insertLast(SET *L, int elem);
void initSet(SET *L);
void displaySET(SET A);
SET unionSET(SET A,SET B);

int main()
{
	SET A,B;
	initSet(&A);
	initSet(&B);
	
	insertLast(&A,2);
	insertLast(&A,4);
	insertLast(&A,6);
	insertLast(&A,8);
	displaySET(A);
	insertLast(&B,1);
	insertLast(&B,3);
	insertLast(&B,5);
	insertLast(&B,7);
	displaySET(B);
	
}

void initSet(SET *L)
{
	*L = NULL;
}

void insertLast(SET *L, int elem)
{
	SET temp,*trav;
	if(temp!=NULL)
	{
		temp =(SET)malloc(sizeof(ctype));
		temp->elem = elem;
		temp->link = NULL;
		for(trav = L;*trav!=NULL;trav = &(*trav)->link){}
		*trav = temp;
	}
}

void displaySET(SET L)
{
	SET trav;
	for(trav = L;trav!=NULL;trav = trav->link)
	{
		printf("SET : %d",trav->elem);
	}
}
