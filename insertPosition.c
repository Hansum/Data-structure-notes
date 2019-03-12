#include <stdio.h>
#include <conio.h>

typedef struct node
{
	char data;
	struct node *link;
}celltype, *List;

void insertPosition(List *L, char elem, int post);
void displayElem(List L);

int main()
{
	List c = NULL;
	char elements;
	int i,position;
//	insertPosition(&c, 'e',1);
//	insertPosition(&c, 'd',3);
//	insertPosition(&c, 'r',1);
//	insertPosition(&c, 'i',10);
	for(i = 0;i<5;i++){
		printf("Enter a number: ");
		scanf("%s",&elements);
		printf("Enter a position: ");
		scanf("%d",&position);
		insertPosition(&c, elements,position);	
	}
		displayElem(c);
	return 0;
	
}

void insertPosition(List *L, char elem, int pos)
{
	List *trav, temp;
	int ctr = 1;
	
	temp = (List)malloc(sizeof(celltype));
	if(temp!=NULL){
		temp->data = elem;
		for(trav = L; *trav!=NULL&&ctr!=pos;trav = &(*trav)->link){
			ctr++;
		}
		if(ctr==pos){
			temp->link= *trav;
			*trav = temp; 
		}else{
			printf("Incorrect position\n");
		}			
	}else{
		printf("Failed to allocate\n");
	}
}

void displayElem(List L)
{
	List trav;
	for(trav = L; trav!=NULL;trav =trav->link){
		printf("%c\n",trav->data);
	}
}
