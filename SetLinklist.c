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
SET intersect(SET A,SET B,SET C);
SET difference(SET A, SET B);
int main()
{
	SET A,B,C,X;
	initSet(&A);
	initSet(&B);
	initSet(&X);
	
	insertLast(&A,2);
	insertLast(&A,4);
	insertLast(&A,6);
	insertLast(&A,8);
	printf("SET A:\n");
	displaySET(A);
	insertLast(&B,1);
	insertLast(&B,4);
	insertLast(&B,5);
	insertLast(&B,6);
	printf("SET B:\n");
	displaySET(B);
	
	printf("Union of SET A and B :\n");
	
	printf("\n");
	
	printf("Intersect of SET A and B:\n");
	C = intersect(A,B,X);
	printf("Result: %d",C);
	printf("\n");
	
	printf("Difference of SET A and B:\n");
	
}

SET unionSet(SET A, SET B)
{
	SET temp, trav,trav2;
	
	for(trav = A; trav!=NULL;)
	{
		for(trav2 = B;trav2!=NULL;)
		{
			temp =(SET)malloc(sizeof(ctype));
			if(trav->elem < trav2->elem)
			{
				temp->elem = trav->elem;
				trav2 = trav2->link;
			}else if(trav->elem == trav2->elem){
				trav = trav->link;
				trav2 = trav2->link;
			}else if(trav->elem > trav2->elem){
				temp->elem = trav2->elem;
				trav = trav->link;
			}
			temp->link = NULL;
			
			return temp;
		}
	}
}

SET intersect(SET A,SET B,SET C) 
{
	SET temp,trav,trav2;
	
	for(trav = A;trav!=NULL;trav = trav->link)
	{
		for(trav2 = B;trav2!=NULL;trav2 =trav2->link)
		{
			temp =(SET)malloc(sizeof(ctype));
			if(trav->elem == trav2->elem)
			{
				temp->elem = trav->elem;
				temp->link = C;
				C = temp;
			}
		}
	}
	return C;
}
SET difference(SET A, SET B)
{
	SET temp,trav;
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
		printf("SET : %d\n",trav->elem);
	}
}
