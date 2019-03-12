#include <stdio.h>
#include <conio.h>

typedef struct node
{
	char data;
	struct node *link;
}celltype, *List;


void insertLast(List *L, char elem);
void displayInsertLast(List L);

void insertLast(List *L, char elem)
{
	List temp, *trav;
	temp = (List)malloc(sizeof(celltype));
	if(temp!=NULL){
		temp->data = elem;
		temp->link = NULL;
	}
		for(trav = L; *trav!=NULL;trav = &(*trav)->link){
		}
		*trav = temp;	
}

void displayInsertLast(List L)
{
	List trav;
	for(trav = L; trav!=NULL;trav = trav->link){
		printf("%c",trav->data);
	}
}

int main()
{
	List c = NULL;
	char elements;
	
	insertLast(&c,'a');
	insertLast(&c,'b');
	insertLast(&c,'c');
	insertLast(&c,'d');
	insertLast(&c,'e');
	displayInsertLast(c);
	return 0;
}
