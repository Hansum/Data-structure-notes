#include <stdio.h>
#include <conio.h>

typedef struct node{
	char data;
	struct node *link;
}ctype,*List;

void init(List *L);
void checkBSIT(List *L, List *X,char elem);
void display(List L);

int main()
{
	List a,b;
	init(&a,&b);
	checkBSIT(&a,&b,"BSIT");
	checkBSIT(&a,&b,"BSICT");
	checkBSIT(&a,&b,"BSCT");
	checkBSIT(&a,&b,"BSIT");
	checkBSIT(&a,&b,"BSCS");
	checkBSIT(&a,&b,"BSICT");
	checkBSIT(&a,&b,"BSIT");
	display(a,b);
	
	return 0;
}

void init(List *L, List *X)
{
	*L = NULL;
}
void checkBSIT(List *L, List *X, char elem)
{
	List temp, *trav;
	if(elem=="BSIT")
	{
		temp = (List)malloc(sizeof(ctype));
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}else{
		temp = (List)malloc(sizeof(ctype));
		temp->data = elem;
		temp->link = *X;
		*X = temp;
	}
}

void display(List L,List X)
{
	List trav,trav2;
	for(trav = L; trav!=NULL;trav = trav->link)
	{
		printf("BSIT :%s",trav->data);
	}
	for(trav2 = X; trav2!=NULL;trav2 = trav2->link)
	{
		printf("NON-BSIT :%s",trav2->data);
	}
}
