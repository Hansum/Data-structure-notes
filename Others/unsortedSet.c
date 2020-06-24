#include <stdio.h>
#include <conio.h>
#define MAX 5
typedef struct node
{
	int data;
	struct node *link;
}ctype, *SET;

void insert(SET *X, int elem);
void unsortedSetB(SET *B, int elem);
void init(SET *A, SET *B);
void display(SET D);
void unionSET(SET A, SET B);

int main()
{
	SET a,b,c;
	int i,elem;
	init(&a,&b);
	for(i=0;i<MAX;i++)
	{
		printf("Enter number for SET A: ");
		scanf("%d",&elem);
		insert(&a,elem);	
	}
	display(a);
	for(i=0;i<MAX;i++)
	{
		printf("Enter number for SET B: ");
		scanf("%d",&elem);
		insert(&b,elem);	
	}
	display(b);
	unionSET(a,b);
	return 0;
}

void init(SET *A, SET *B)
{
	*A = NULL;
	*B = NULL;
}
void insert(SET *X, int elem)
{
	SET temp,Btemp,check,*trav;
	temp = (SET)malloc(sizeof(ctype));
	if(temp!=NULL)
	{
		temp->data = elem;
		temp->link = *X;
		*X=temp;
	}
	
}

void display(SET D)
{
	SET trav,Btrav,Ctrav;
	for(trav = D;trav!=NULL; trav = trav->link)
	{
		printf("SET: {%d}\n",trav->data);
	}
}
void unionSET(SET A, SET B)
{
	SET Atrav,Btrav, C,temp;
	int i;
	temp = (SET)malloc(sizeof(ctype));
	for(Atrav = A;Atrav!=NULL;Atrav = Atrav->link)
	{
		for(Btrav = B; Btrav!=NULL&& Btrav->data!=Atrav->data;Btrav = Btrav->link){}
		if(Btrav!=NULL)
		{
			temp->data = Btrav->data;
			Btrav = temp->link;
			C = temp;
		}
		printf("SET C: %d", C);
	}
}
