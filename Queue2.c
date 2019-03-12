#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
	char data;
	struct node *link;
}ctype, *List;

typedef struct{
	List front;
	List rear;
	int count;
}Queue;

void initQueue(Queue *Q);
void Enqueue(Queue *Q, char elem);
void Dequeue(Queue *Q);
//void display(List L);

void initQueue(Queue *Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->count = 0;
}

int main()
{
	Queue c;
	//List x;
	int i,e;
	
	for(i = 0; i<MAX;i++)
	{
		printf("Enter integer: ");
		scanf("%d", &e);
		Enqueue(&c,e);
	}
	//display(c);
	Dequeue(&c);
}

//void display(List L)
//{
//	int i;
//	List trav;
//	for(i=0;i<MAX;i++)
//	{
//		printf("Queue list: %d",trav->data);
//	}
//}

void Enqueue(Queue *Q, char elem)
{
	List temp;
	temp=(List)malloc(sizeof(ctype));
	if(temp!=NULL)
	{
		temp->data = elem;
		temp->link = NULL;
		if(Q->count == 0)
		{
			Q->front = Q->rear = temp;
		}else{
			Q->rear->link = temp;
		}
		Q->rear = temp;
		Q->count++;
		//printf("FRONT NODE IS: %d", Q->front->data);
	}
}

void Dequeue(Queue *Q)
{
	List temp;
	if(Q->front!=NULL){
		printf("FRONT NODE IS: %d", Q->front->data);
		temp = Q->front;
		Q->front = temp->link;
		free(temp);
		Q->count--;
		if(Q->front==NULL)
		{
			Q->rear = NULL;
			printf("Both front and rear are NULL");
		}
		printf("\nREAR NODE IS: %d",Q->rear->data);
	}
}
