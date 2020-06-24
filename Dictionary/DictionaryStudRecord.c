#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 25

typedef struct{
	char course[8];
	int year;
	int id;
	char name[15];
}studRec;

typedef struct node{
	studRec stud;
	struct node *link;
}*List;

typedef List Dictionary[SIZE];

typedef enum{TRUE,FALSE}boolean;

int Hash(char name[]);
void init(Dictionary D);
void insert(Dictionary D, studRec stud);
void deleteElem(Dictionary D, studRec stud);
boolean isMember(Dictionary D, studRec stud);
void displayHash(Dictionary D);

int main()
{
	Dictionary x;
	studRec record;
	boolean result;
	init(x);
	
	
	strcpy(record.course,"BSIT");
	record.id = 1;
	strcpy(record.name,"Dom");
	record.year = 4;
	insert(x,record);
	
	strcpy(record.course,"BSCS");
	record.id = 2;
	strcpy(record.name,"Christian");
	record.year = 4;
	insert(x,record);
	
	strcpy(record.course,"BSIT");
	record.id = 3;
	strcpy(record.name,"Edrian");
	record.year = 4;
	insert(x,record);
	
	strcpy(record.course,"BSIT");
	record.id = 3;
	strcpy(record.name,"Donne");
	record.year = 4;
	insert(x,record);
	
	strcpy(record.course,"BSIT");
	record.id = 4;
	strcpy(record.name,"Jose");
	record.year = 4;
	insert(x,record);
	
	strcpy(record.course,"BSCS");
	record.id = 5;
	strcpy(record.name,"Jason");
	record.year = 4;
	insert(x,record);
	
	displayHash(x);
	
	printf("\n\nDELETE: \n");
	strcpy(record.course,"BSCS");
	record.id = 5;
	strcpy(record.name,"Jason");
	record.year = 4;
	deleteElem(x,record);
	
	displayHash(x);
	
	printf("\n");
	printf("0 =  TRUE & 1 = FALSE\n");
	strcpy(record.name,"Edrian");
	record.id = 3;
	result = isMember(x,record);
	printf("Member: %d",result);
	
	return 0;
}

void init(Dictionary D)
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		D[i] = NULL;
	}
}

int Hash(char name[])
{
	return name[0] - 65;
}

void insert(Dictionary D, studRec stud)
{
	List temp, *trav;
	int val;
	
	val = Hash(stud.name);
	
	for(trav = &D[val]; *trav!=NULL && (*trav)->stud.id != stud.id; trav = &(*trav)->link){}
	
	if(*trav == NULL || (*trav)->stud.id != stud.id){
		temp = (List)malloc(sizeof(struct node));
		temp->stud = stud;
		temp->link = NULL;
		*trav = temp;
	}
}

void deleteElem(Dictionary D, studRec stud)
{
	List temp,*trav;
	int val;
	
	val = Hash(stud.name);
	
	for(trav = &D[val]; *trav!=NULL && (*trav)->stud.id != stud.id; trav = &(*trav)->link){}
	
	if(*trav !=NULL){
		temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

boolean isMember(Dictionary D, studRec stud)
{
	List *trav;
	boolean res = FALSE;
	int val;
	
	val = Hash(stud.name);
	
	for(trav = &D[val]; *trav!=NULL; trav = &(*trav)->link){
		if(*trav != NULL && (*trav)->stud.id == stud.id){
			res = TRUE;
		}
	}
	return res;
}

void displayHash(Dictionary D)
{
	int i;
	List *trav;
	
	for(i = 0; i < SIZE; i++){
		printf("[%c]\n", i + 'A');
		for(trav = &D[i]; *trav !=NULL; trav = &(*trav)->link){
			printf("COURSE: %s\n", (*trav)->stud.course);
			printf("ID: %d\n", (*trav)->stud.id);
			printf("YEAR: %d\n", (*trav)->stud.year);
			printf("NAME: %s\n", (*trav)->stud.name);
		}
	}
}
