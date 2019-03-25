#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef int List;

typedef struct{
	char data;
	int link;
}Stack;

typedef struct{
	int availList;
	Stack stackArray[SIZE];
}VirtualHeap;

void StackInit(VirtualHeap *H);
void StackPush(VirtualHeap *H, char elem, List *L);
void StackPop(VirtualHeap *H, List *L);
char StackTop(VirtualHeap *H, List *L);
void display(VirtualHeap *H, List L);

int main()
{
	VirtualHeap x;
	List y;
	char retval;
	y=-1;
	
	StackInit(&x);
	StackPush(&x,'a',&y);
	StackPush(&x,'x',&y);
	StackPush(&x,'c',&y);
	StackPush(&x,'v',&y);
	StackPush(&x,'b',&y);
	display(&x,y);
	retval = StackTop(&x,&y);
	printf("Top element: %c",retval);
	return 0;
}


void StackInit(VirtualHeap *H)
{
	List i;
	
	for(i=SIZE-1;i>-1;i--)
	{
		H->stackArray[i].link = i-1;
	}
	H->availList = SIZE-1;
}
void StackPush(VirtualHeap *H, char elem, List *L)
{
	List temp;
	temp = H->availList;
	if(temp!=-1)
	{
		H->availList = H->stackArray[temp].link;
		H->stackArray[temp].data = elem;
		H->stackArray[temp].link = *L;
		*L = temp;
	}
}
void StackPop(VirtualHeap *H, List *L)
{
	List temp;
	
	temp = *L;
	*L = H->stackArray[temp].link;
	free(temp);
	
}
char StackTop(VirtualHeap *H, List *L)
{
	List temp;
	char elem;
	
	temp = *L;
	elem = H->stackArray[temp].data;
	
	return elem;
	
}
void display(VirtualHeap *H, List L)
{
	List trav;
	for(trav=L; trav!=-1;trav = H->stackArray[trav].link)
	{
		printf("Elements: %c\n", H->stackArray[trav].data);	
	}
}
