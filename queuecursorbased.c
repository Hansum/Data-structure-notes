#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef struct{
	char data;
	int link;
}Node;

typedef int List;

typedef struct{
	Node nodeArray[SIZE];
	int availList;
}VirtualHeap;

typedef struct{
	List front;
	List rear;
}Queue;


void initVHEAP(VirtualHeap *H);
void initQueue(Queue *Q);
void enqueue(VirtualHeap *H, char elem, Queue *Q);
void display(VirtualHeap *H, Queue *Q);


int main()
{
	VirtualHeap x;
	Queue q;
	
	initVHEAP(&x);
	initQueue(&q);
	enqueue(&x,'a',&q);
	enqueue(&x,'b',&q);
	enqueue(&x,'c',&q);
	enqueue(&x,'d',&q);
	enqueue(&x,'e',&q);
	enqueue(&x,'f',&q);
	
	display(&x,&q);
	
	return 0;
}

void initVHEAP(VirtualHeap *H)
{
	List i;
	for(i=SIZE-1;i>-1;i--)
	{
		H->nodeArray[i].link = i-1;
	}
	H->availList = SIZE-1;
}

void initQueue(Queue *Q)
{
	Q->front = -1;
	Q->rear = -1;
}

void enqueue(VirtualHeap *H, char elem, Queue *Q)
{
	List temp;
	temp = H->availList;
	if(temp!=-1)
	{
		H->availList = H->nodeArray[temp].link;
		H->nodeArray[temp].data = elem;
		H->nodeArray[temp].link = -1;
		
		if(Q->front == -1)
		{
			Q->front = temp;
		}else{
			Q->rear = H->nodeArray[Q->rear].link;
		}
		Q->rear = temp;
	}
}

void display(VirtualHeap *H, Queue *Q)
{
	printf("FRONT QUEUE: %c\n", H->nodeArray[Q->front].data);
	printf("REAR QUEUE: %c", H->nodeArray[Q->rear].data);
}
