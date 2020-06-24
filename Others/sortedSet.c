#include <stdio.h>
#include <conio.h>

typedef struct node
{
	int data;
	struct node *link;
}ctype, *SET;

void init(SET *L);
void insert(SET *L, int elem);
void sortedSet(SET L);
void display(SET L);

int main()
{
	SET A,B;
	init(&A);
	init(&B);
	insert(&A,3);
	insert(&A,4);
	insert(&A,1);
	insert(&A,2);
	insert(&A,5);
	sortedSet(A);
	display(A);
	insert(&B,3);
	insert(&B,2);
	insert(&B,8);
	insert(&B,1);
	insert(&B,7);
	sortedSet(B);
	display(B);
	return 0;
}

void init(SET *L)
{
	*L = NULL;
}

void insert(SET *L, int elem)
{
	SET temp;
	temp = (SET)malloc(sizeof(ctype));
	if(temp!=NULL)
	{
		temp->data = elem;
		temp->link = *L;
		*L=temp;
	}
}
void sortedSet(SET L)
{
	SET temp, trav, small, cur;
	for(cur = L; cur!=NULL;cur = cur->link)
	{
		if(cur!=NULL)
		{
			small = cur;
			for(trav = cur->link;trav!=NULL;trav = trav->link)
			{
				if(small->data > trav->data)
				{
					small = trav;
				}
			}
		}
		if(cur!=small)
		{
			temp = cur->data;
			cur->data = small->data;
			small->data = temp;
		}
	}
}

//void setSorted(SET A, SET B)
//{
//	SET temp,trav,C;
//	C= NULL;
//	temp = (SET)malloc(sizeof(ctype));
//	if(temp!=NULL)
//	{
//		temp->data = A->data;
//		temp->link = C;
//		C = temp;
//		A = A->link;
//	}
//	for(trav = B;trav!=NULL&&trav->data!=C->data;trav = trav->link){}
//	temp = (SET)malloc(sizeof(ctype));
//	if(trav!=NULL)
//	{
//		temp->data = B->data;
//		temp->link = C;
//		C= temp;
//	}
//	printf("SET C: %d",C);
//	
//}

void display(SET L)
{
	SET trav;
	for(trav = L;trav!=NULL;trav = trav->link)
	{
		printf("SET: %d\n",trav->data);
	}
}
