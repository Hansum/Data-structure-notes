#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef int List;

typedef struct{
	char data;
	int link;
}Node;

typedef struct{
	Node nodeArray[SIZE];
	int availList;
}VirtualHeap;

typedef struct{
	List front;
	List rear;
}Queue;

void initVHeap(VirtualHeap *H);
void initQueue(Queue *Q);
void VHeapEnqueue(VirtualHeap *H, char elem, Queue *Q);
void VHeapDequeue(VirtualHeap *H, Queue *Q);
void displayEnqueue(VirtualHeap H, Queue Q);
void displayDequeue(VirtualHeap H, Queue Q);


int main()
{
	VirtualHeap x;
	Queue q;
	initVHeap(&x);
	initQueue(&q);
	
	VHeapEnqueue(&x,'t',&q);
	VHeapEnqueue(&x,'x',&q);
	VHeapEnqueue(&x,'c',&q);
	VHeapEnqueue(&x,'v',&q);
	VHeapEnqueue(&x,'h',&q);
	VHeapEnqueue(&x,'q',&q);
	VHeapEnqueue(&x,'e',&q);
	displayEnqueue(x,q);
	
	VHeapDequeue(&x,&q);
	displayDequeue(x,q);
	
	return 0;
}

void initVHeap(VirtualHeap *H)
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
	Q->front = Q->rear = -1;
}
void VHeapEnqueue(VirtualHeap *H, char elem, Queue *Q)
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
			H->nodeArray[Q->rear].link = temp;
		}
		Q->rear = temp;
	}
}

void VHeapDequeue(VirtualHeap *H, Queue *Q)
{
	List temp;
	temp = Q->front;
	if(temp!=-1)
	{
		Q->front = H->nodeArray[temp].link;
		H->nodeArray[temp].link = H->availList;
		H->availList = temp;
		if(Q->front == -1)
		{
			Q->rear = -1;
		}
	}
}

void displayEnqueue(VirtualHeap H, Queue Q)
{
	printf("ENQUEUE\n");
	printf("Front queue: %c\n", H.nodeArray[Q.front].data);
	printf("Rear queue: %c\n", H.nodeArray[Q.rear].data);
}

void displayDequeue(VirtualHeap H, Queue Q)
{
	printf("\nDEQUEUE\n");
	printf("New Front queue: %c\n", H.nodeArray[Q.front].data);
	printf("Rear queue: %c\n", H.nodeArray[Q.rear].data);
}
