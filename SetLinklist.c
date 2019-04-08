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
void intersect(SET A,SET B,SET *C);
void difference(SET A, SET B, SET *D);
int main()
{
	SET A,B,C,D,X;
	initSet(&A);
	initSet(&B);
	initSet(&D);
	initSet(&X);
	
	insertLast(&A,1);
	insertLast(&A,3);
	insertLast(&A,5);
	insertLast(&A,6);
	insertLast(&A,7);
	insertLast(&A,9);
	printf("SET A:\n");
	displaySET(A);
	insertLast(&B,3);
	insertLast(&B,8);
	insertLast(&B,4);
	insertLast(&B,5);
	insertLast(&B,7);
	insertLast(&B,9);
	printf("SET B:\n");
	displaySET(B);
	
	printf("Union of SET A and B :\n");
	
	printf("\n");
	
	printf("Intersect of SET A and B:\n");
	intersect(A,B,&X);
	displaySET(X);
	printf("\n");
	
	printf("Difference of SET A and B:\n");
	difference(A,B,&D);
	displaySET(D);
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

void intersect(SET A,SET B,SET *C) 
{
	SET temp,trav,trav2;
	
	for(trav = A;trav!=NULL;trav = trav->link)
	{
		for(trav2 = B;trav2!=NULL;trav2 =trav2->link){
			if(trav->elem == trav2->elem)
			{
				temp =(SET)malloc(sizeof(ctype));
				temp->elem = trav->elem;
				temp->link = *C;
				*C = temp;
			}
		}
	}
	
}
void difference(SET A, SET B,SET *D)
{
	SET temp,trav,trav2;
	
	for(trav = A;trav!=NULL;trav = trav->link)
	{
		for(trav2 = B;trav2!=NULL && trav->elem != trav2->elem;trav2 =trav2->link){}
		
		if(trav2 ==NULL)
		{
			temp = (SET)malloc(sizeof(ctype));
			temp->elem = trav->elem;
			temp->link = *D;
			*D = temp;
		}
	}
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
