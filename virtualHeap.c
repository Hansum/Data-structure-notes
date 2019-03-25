#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 8

typedef struct{
	char data;
	int link;
}Node;

typedef struct{
	Node nodeArray[MAX-1];
	int availList;
}VirtualHeap;

typedef int List; //making List a int datatype variable

void insertFirst(List *L, char elem, VirtualHeap *H);
void initVirtualHeap(VirtualHeap *H);
int getNode(VirtualHeap *H);
void returnNode(VirtualHeap *H, int num); //or List num
void insertLast(VirtualHeap *H, List *L);

int main()
{
	List i, num, L;
	L = -1;
	
	VirtualHeap VH;
	
	initVirtualHeap(&VH);
	for(i=0;i<=MAX-1;i++)
	{
		printf("Enter integer ");
		scanf("%d",&num);
		insertFirst(&L,num,&VH);
	}
}

void initVirtualHeap(VirtualHeap *H)
{
	int i;
	
	for(i=0;i<MAX-1;i++)
	{
		H->nodeArray[i].link = i+1;
	}
	H->nodeArray[MAX-1].link = -1;
	H->availList = 0;
}

void insertFirst(List *L, char elem, VirtualHeap *H)
{
	List temp;
	temp = getNode(H);//1
	if(temp!=-1) //5
	{
		H->nodeArray[temp].data = elem; //6
		H->nodeArray[temp].link = *L; //7
		*L = temp; //8
	}
}

int getNode(VirtualHeap *H) //malloc for array
{
	List temp; //int temp; since List = int
	temp = H->availList; //temp gets the value of H->availList //2
	if(temp!=-1)
	{
		H->availList = H->nodeArray[temp].link; //3
	}
	return temp; //4
}

void returnNode(VirtualHeap *H, int num) //check if the index is available in the list
{
	if(num >=0 && num<=MAX-1)
	{
		H->nodeArray[num].link = H->availList;
		H->availList = num;
	}
}
