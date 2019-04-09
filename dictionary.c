#include <stdio.h>
#include <conio.h>
#define SIZE 10

typedef struct node{
	int elem;
	struct node *link;
}*List;

typedef List Dictionary[SIZE];

typedef enum{TRUE, FALSE}boolean;

int Hash(int elem);
void initDictionary(Dictionary D);
void insert(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
boolean isMember(Dictionary D, int elem);
void display(Dictionary D);


int main()
{
	Dictionary X;
	boolean res;
	
	initDictionary(X);
	
	insert(X,12);
	insert(X,32);
	insert(X,58);
	insert(X,45);
	insert(X,19);
	insert(X,28);
	insert(X,88);
	printf("DATA INSERTED IN ITS REPESCTED INDEX:");
	display(X);
	
	printf("\nDELETE GIVEN ELEMENT:");
	deleteElem(X,88);
	display(X);
	
	printf("\nCHECK IF THE GIVEN ELEMENT IS A MEMBER");
	res = isMember(X,88); //0 = TRUE WHILE 1 = FALSE
	printf("\nMEMBER: %d",res);
	
	
	return 0;
}

void initDictionary(Dictionary D)
{
	int i;
	
	for(i=0;i<SIZE;i++)
	{
		D[i] = NULL;
	}
}

int Hash(int elem)
{
	return elem % 10;
}

void insert(Dictionary D, int elem)
{
	List temp, *trav;
	int val;
	
	val = Hash(elem);
	
	for(trav = &D[val];*trav!=NULL && (*trav)->elem < elem;trav = &(*trav)->link){}
	
	if(*trav == NULL || (*trav)->elem!=elem){
		temp = (List)malloc(sizeof(struct node));
		temp->elem = elem;
		temp->link = *trav;
		*trav = temp;
	}
}

void deleteElem(Dictionary D, int elem)
{
	List temp, *trav;
	int val;
	
	val = Hash(elem);
	for(trav = &D[val];*trav!=NULL && (*trav)->elem != elem;trav = &(*trav)->link){}
		if(*trav!=NULL){
			temp = *trav;
			*trav = temp->link;
			free(temp);
		}
}

boolean isMember(Dictionary D, int elem)
{
	List *trav;
	int val;
	boolean res = FALSE;
	val = Hash(elem);
	
	for(trav = &D[val];*trav!=NULL;trav = &(*trav)->link){
		if(*trav!=NULL && (*trav)->elem == elem){
			res = TRUE;
		}
	}
	return res;
}

void display(Dictionary D){
	int i;
	List *trav;
	for(i=0;i<SIZE;i++){
		printf("\nD[%d] = ",i);
		for(trav = &D[i];*trav!=NULL;trav = &(*trav)->link){
			printf("%d ",(*trav)->elem);
		}
	}
}
