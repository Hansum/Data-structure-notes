#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6

typedef struct node
{
	char data[MAX];
	struct node *link;
}ctype, *List;

typedef struct
{
	List head;
	List rear;
}Queue;


void arrayEnqueue(Queue *L, char *elem);
void arrayDequeue(Queue *L);
void displayHead(Queue L);
void displayRear(Queue L);

int main()
{
	
	int i;
	Queue c;
	c.head = NULL;
	c.rear = NULL;
//	char x[MAX] = {'A','B','C','D','E','F'};
	char x[MAX];
	for(i = 0;i<MAX;i++)
	{
		//printf("elements: %c\n", x[i]);
		printf("Enter element: ");
		scanf("%s",&x[i]);
		arrayEnqueue(&c,x);
	}
	displayHead(c);

//	while(c.head!=NULL){
//		displayHead(c);
//	}
	
	getch();
	return 0;
}


void arrayEnqueue(Queue *L, char *elem)
{
	List temp;
	temp = (List)malloc(sizeof(ctype));
	if(temp!=NULL)
	{
		strcpy(temp->data,elem);
		temp->link = NULL;
		if(L->head == NULL) // L->head == -1 && L->rear == -1
		{
			L->head = L->rear = temp;
		}else{
			L->rear->link = temp;
			L->rear = temp;
		}
	}
}

void arrayDequeue(Queue *L)
{
	List temp;
	temp = L->head;
	L->head = temp->link;
	free(temp);
	if(L->head == L->rear)
	{
		L->head = NULL;
		L->rear = NULL;
	}
	
	printf("\nRear element: %c",L->rear->data);
}

void displayHead(Queue L)
{
	if(L.head!=NULL)
	{
		printf("Head element: %c", L.head->data);
		arrayDequeue(&(L));
	}
}



