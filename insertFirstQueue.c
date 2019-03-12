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
