#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 6

typedef struct node{
	char data[MAX];
	struct node *link;
}ctype,*List;

typedef struct{
	List front;
	List rear;
}Queue;

void arrayEnqueue(Queue *L, char elem);
void arrayDequeue(Queue *L);
void display(Queue L);

int main()
{
	Queue q;
	q.front = NULL;
	q.rear = NULL;
	
	
}

void arrayEnqueue(Queue *L, char elem)
{
	
}
void arrayDequeue(Queue *L)
{
	
}
void display(Queue L)
{
	
}

