#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 6

typedef struct node
{
	int data;
	struct node *link;
}ctype, *List;

typedef struct
{
	List head;
	List rear;
}Queue;

void enqueue(Queue *L, char elem);
void dequeue(Queue *L);
//void display(Queue *L);
void displayFront(Queue L);
void displayRear(Queue L);

int main()
{
	Queue q;
	int i;
	int element;

	
	q.head = NULL;
	q.rear = NULL;
	
	for(i = 0; i<MAX;i++)
	{
		printf("Enter element: ");
		scanf("%d", &element);
		enqueue(&q,element);
	}

//	while(q.head!=NULL)
//	{
//		display(&q);	
//	}
	displayFront(q);
	
	for(i = 0; i<MAX;i++)
	{
		dequeue(&q);	
	}
	displayRear(q);
	
	return 0;
	
}
//void display(Queue *L)
//{
//	if(L->head!=NULL)
//	{
//		printf("%c", L->head->data);
//		dequeue(&(*L));
//	}
//}

void enqueue(Queue *L, char elem)
{
	List temp;
	temp = (List)malloc(sizeof(ctype));
	if(temp!=NULL){
		temp->data = elem;
		temp->link = NULL;	
		if(L->head ==NULL && L->rear == NULL){
			L->head = L->rear = temp;
			return;
		}else{
			L->rear->link = temp; 
			L->rear = temp;                                                                        
		}
	}
	
	
}
void dequeue(Queue *L)
{
	List temp;
	temp = L->head;
	if(L->head == NULL)
	{
		return;	
	}else{
		L->head = L->head->link;
	}
	free(temp);	
}

void displayFront(Queue L)
{
	if(L.head!=NULL)
	{
		printf("Front/head element is: %d",L.head->data);
	}
		
}
void displayRear(Queue L)
{
	if(L.rear!=NULL)
	{
		printf("\nRear element is: %d",L.rear->data);
	}
		
}



