#include <stdio.h>
#include <conio.h>
#define SIZE 5

typedef struct{
	int data;
	int link;
}Node;

typedef struct{
	Node nodeArray[SIZE];
	int availList;
}VirtualHeap;

typedef int List;

typedef struct{
	List front;
	List rear;
}Queue;

void CursorEnqueue(Queue *Q, VirtualHeap *H, int elem);
void CursorDequeue(Queue *Q, VirtualHeap *H);
void displayCursorEnqueue(Queue Q, VirtualHeap H);
void initVHeap(VirtualHeap *H);
void returnNode(VirtualHeap *H, int num);
void initQueue(Queue *Q);

int main()
{
	VirtualHeap A;
	Queue C;
	List i;
	int element;
	
	initVHeap(&A);
	initQueue(&C);
//	for(i=0;i<SIZE-1;i++)
//	{
//		printf("Enter element: ");
//		scanf("%d",&element);
//		CursorEnqueue(&C,&A,element);
//	}
	CursorEnqueue(&C,&A, 1);
	CursorEnqueue(&C,&A, 2);
	CursorEnqueue(&C,&A, 3);
	CursorEnqueue(&C,&A, 4);
	CursorEnqueue(&C,&A, 5);
	displayCursorEnqueue(C,A);
	
	return 0;
}

void initVHeap(VirtualHeap *H)
{
	List i;
	
//	for(i=SIZE-1;i>-1;i--)
//	{
//		H->nodeArray[i].link = i-1;
//	}
//	H->availList = SIZE-1;

	for(i=0;i<SIZE-1;i++)
	{
		H->nodeArray[i].link = i+1;
	}
	H->nodeArray[SIZE-1].link = -1;
	H->availList = 0;
}

void initQueue(Queue *Q)
{
	Q->front = -1;
	Q->rear = -1;
}

void CursorEnqueue(Queue *Q, VirtualHeap *H, int elem)
{
	List temp;
	temp = H->availList;
	if(temp!=-1)
	{
		H->availList = H->nodeArray[temp].link;
		H->nodeArray[temp].data = elem;
		H->nodeArray[temp].link = -1;
		if(Q->front != -1)
		{
			H->nodeArray[Q->rear].link = temp;
		}else{
			Q->front = temp;
		}
		Q->rear = temp;
	}
}

void CursorDequeue(Queue *Q, VirtualHeap *H)
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

//void returnNode(VirtualHeap *H, int num)
//{
//	if(num>=0&&num<SIZE-1)
//	{
//		H->nodeArray[num] = H->availList;
//		H->availList = num;
//	}
//}

void displayCursorEnqueue(Queue Q, VirtualHeap H)
{
		printf("Front queue: %d\n", H.nodeArray[Q.front].data);
		printf("Rear queue: %d\n", H.nodeArray[Q.rear].data);
	
}

