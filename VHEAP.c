#include <stdio.h>
#include <conio.h>
#define MAX 8


typedef struct{
	int elem;
	int link;
}Node;

typedef struct node{
	Node nodeArray[MAX];
	int availList;
}VirtualHeap;

typedef int List;

void initVHeap(VirtualHeap *H);
int getNode(VirtualHeap *H);
void returnNode(VirtualHeap *H, int num);
void insertFirst(List *L, int element, VirtualHeap *H);
void display(VirtualHeap H);


void initVHeap(VirtualHeap *H)
{
	int i,size;
	size = MAX-1;
	for(i=0;i<size;i++)
	{
		(*H)->nodeArray[i].link = i+1;
	}
	(*H)->nodeArray[size-1].link = -1;
	(*H)->availList = 0;
}

int getNode(VirtualHeap *H)
{
	List temp;//int temp
	temp = H->availList;
	if(temp!=-1)
	{
		H->availList = H->nodeArray[temp].link;
	}
	return temp;
}

void returnNode(VirtualHeap *H, int num)
{
	if(num>=0&&num<=MAX-1)
	{
		H->nodeArray[num].link = H->availList;
		H->availList = num;
	}
}

void insertFirst(List *L, int element, VirtualHeap *H)
{
	List temp;
	temp = getNode(H);
	if(temp!=-1)
	{
		H->nodeArray[temp].elem = element;
		H->nodeArray[temp].link = *L;
		*L = temp;
	}
}

//void displayVHeap(VirtualHeap V, head header)
//{
//    int x;
//    
//    for(x = header; V.NODES[x].next != -1 ;x = V.NODES[x].next){
//          puts(V.NODES[x].elem.LN);
//          } 
//  
//}
//void display(VirtualHeap H)
//{
//	VirtualHeap temp;
//	
//	for(temp = H; temp!=-1; temp = &(H->nodeArray[temp].link))
//	{
//		printf("List: %c", H->nodeArray[temp].elem);
//	}
//}

int main()
{
	int i;
	char x;
	VirtualHeap *VH;
	List l;
	
	VH = (VirtualHeap)malloc(sizeof(struct node));
	initVHeap(&VH);
	for(i=0;i<MAX-1;i++)
	{
		printf("Enter element: ");
		scanf("%d",&x);
		insertFirst(&l,x,&VH);
	}
//	display(VH);
	
	return 0;
}
