#include <stdio.h>
#include <conio.h>

typedef struct node
{
	char data;
	struct node *link;
}celltype, *List;


void insertFirst(List *L, char elem);
void displayInsertFirst(List L);


void insertFirst(List *L, char elem)
{
	List temp;
	temp = (List)malloc(sizeof(celltype));
	if(temp!=NULL){
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}
}
void displayInsertFirst(List L)
{
	List trav;
	for(trav = L; trav!=NULL;trav = trav->link){
		printf("%d",trav->data);
	}
}

int main()
{
	List c = NULL;
	int elements;
	int i;
	
	for(i = 0; i<5; i++)
	{
		printf("Enter element: ");
		scanf("%d", &elements);
		
		insertFirst(&c, elements);
	}
	displayInsertFirst(c);
}
