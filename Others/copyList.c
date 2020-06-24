#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct{
	char FN[24];
	char LN[16];
	char MI;
}nameType;

typedef struct{
	nameType name;
	unsigned long ID;
	char course[8];
	int year;
}studrec;

typedef struct node{
	studrec stud;
	struct node *link;
}ctype, *List;

List copyBSIT(List *L);
void displayBSIT(List *L);
void init(List *L);
void insertFirst(List *L, char *elem);

int main()
{
	List c;
	List it;
	
	init(&c);
	insertFirst(&c,"BSICT");
	insertFirst(&c,"BSIT");
	insertFirst(&c,"BSIT");
	insertFirst(&c,"BSCS");
	insertFirst(&c,"BSIT");
	it = copyBSIT(&c);
	displayBSIT(&it);
	return 0;
}


void init(List *L)
{
	*L = NULL;
}

void insertFirst(List *L, char *elem)
{
	List temp;
	int i = 0;
	temp =(List)malloc(sizeof(ctype));
	if(temp!=NULL)
	{
		strcpy(temp->stud.course, elem);
		temp->link = *L;
		*L=temp;
	}
}

List copyBSIT(List *L)
{
	List temp, *trav;
	List newlist = NULL;
	for(trav = L; *trav!=NULL;)
	{
		if(strcmp((*trav)->stud.course, "BSIT")==0)
		{
			temp = *trav;
			*trav = temp->link;
			temp->link = newlist;
			newlist = temp;
		}else{
			trav = &(*trav)->link;
		}
	}
	return newlist;
}

void displayBSIT(List *L)
{
	printf("NUMBER OF BSIT: %s",(*L)->stud.course);
}
