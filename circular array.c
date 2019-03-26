#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef struct{
	char data[SIZE];
	int front;
	int rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char elem);
void display(Queue *Q);

void init(Queue *Q)
{
	Q->front = 1;
	Q->rear = 0;
}

int main()
{
	Queue x;
	int i = 0;
	char element;
	init(&x);
	
	while(i<SIZE)
	{
		printf("Enter element: ");
		scanf("%s",&element);
		enqueue(&x,element);
		i++;
	}
	dequeue(&x);
	display(&x);
	return 0;
}

void enqueue(Queue *Q, char elem)
{
	if((Q->rear+2)%SIZE != Q->front){
		Q->rear = (Q->rear+1)%SIZE;
		Q->data[Q->rear] = elem;
	}
}

void dequeue(Queue *Q)
{
	if((Q->rear+1)%SIZE!=Q->front)
	{
		Q->front = (Q->front+1)%SIZE;
	}
}

void display(Queue *q)
{
	printf("Front: %c\n", q->data[q->front]);
	printf("Rear: %c",q->data[q->rear]);
}
