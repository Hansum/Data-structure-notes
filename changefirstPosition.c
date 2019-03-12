#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct{
	unsigned long ID;
}studrec;

typedef struct node{
	studrec stud;
	struct node *link;
}celltype, *List;

int FindDelete(List *L, unsigned long studId);
void insertList(List *L, unsigned long a);
void display(List L);


int main()
{
	List c = NULL;
	unsigned long x, y;
	int i;
	
	for(i = 0; i<3;i++){
		printf("\nEnter Id you want to insert in the list: ");
		scanf("%lu", &y);
		insertList(&c,y);
	}
	display(c);
	printf("\nEnter id you want to find in the list: ");
	scanf("%lu", &x);
	FindDelete(&c, x);
	display(c);
	
	return 0;
}

void insertList(List *L, unsigned long a)
{
    List *ins,temp;
    for(ins = L; *ins!=NULL;ins = &(*ins)->link){ }
    temp = (List)malloc(sizeof(celltype));
    if(temp!=NULL){
    temp->stud.ID=a;
    temp->link=NULL;
    *ins = temp;
	}
}

int FindDelete(List *L, unsigned long studId)
{
	int isFound;
	List *trav, temp;
	
	for(trav = L; *trav!=NULL&&(*trav)->stud.ID!=studId;trav = &(*trav)->link){}
	if(*trav!=NULL){
		temp = *trav;
		*trav = temp->link;
		temp->link = *L;
		*L = temp;
		isFound = 1;
	}else{
		isFound = 0;
	}
	return isFound;
}

void display(List L)
{
	List trav;
	for(trav = L; trav!=NULL;trav = trav->link){
		printf("result is: %lu\n",trav->stud.ID);
	}
}



