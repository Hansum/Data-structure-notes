#include <stdio.h>
#include <conio.h>
#define SIZE 20
#define DELETED 0
#define EMPTY -1

typedef struct{
	int year;
	unsigned int IDen;
	char course[10];
	char name[15];
}studrec;

typedef struct{
	studrec stud;
	int link;
}node;

typedef struct{
	node NodeArray[SIZE];
	int avail;
}Dictionary;


void initDictionary(Dictionary *D);
int Hash(int elem);
int isMember(Dictionary D,int elem, int HashValue);
void insertElement(Dictionary *D, studrec Rec);
void deleteElement(Dictionary *D, studrec Rec);
void display(Dictionary D);


int main()
{
	Dictionary d;
	initDictionary(&d);
	studrec record;
	
	record.IDen = 1;
	insertElement(&d,record);
	
	record.IDen = 6;
	insertElement(&d,record);
	
	record.IDen = 13;
	insertElement(&d,record);
	
	record.IDen = 18;
	insertElement(&d,record);
	
	record.IDen = 15;
	insertElement(&d,record);
	
	record.IDen = 18;
	insertElement(&d,record);
	
	record.IDen = 16;
	insertElement(&d,record);
	
	record.IDen = 16;
	insertElement(&d,record);
	
	record.IDen = 1;
	deleteElement(&d,record);
	
	display(d);
	
	return 0;
}

void initDictionary(Dictionary *D)
{
	int i,j;
	
	for (i=0;i<SIZE/2;i++) {
		D->NodeArray[i].stud.IDen = EMPTY;
		D->NodeArray[i].link = EMPTY;
	}
	
	for (j=i;j<SIZE-1;j++) {
		D->NodeArray[j].link = j+1;
	}
	
	D->NodeArray[SIZE-1].link = -1;
	D->avail = SIZE/2;
	
}

int Hash(int elem)
{
	int sum = 0;
	while (elem!=0) {
		sum += (elem%10);
		elem /=10;
	}
	return sum % 10;
}

int isMember(Dictionary D,int elem, int HashValue)
{
	int retval,i;
	retval = 0;
	
	if (D.NodeArray[HashValue].stud.IDen != EMPTY) {
		i = (D.NodeArray[HashValue].stud.IDen == DELETED) ? D.NodeArray[HashValue].link : HashValue;
		
		for ( ; i!= -1 && D.NodeArray[HashValue].stud.IDen != elem; i = D.NodeArray[HashValue].link) {}
		
		if (i!=-1) {
			retval = 1;
		}
	}
	return retval;
}
void insertElement(Dictionary *D, studrec Rec)
{
	int val,temp,member;
	
	val = Hash(Rec.IDen);
	member = isMember(*D,Rec.IDen,val);
	
	/*	
	 1 = member
	 0 = not a member
	*/
	if (member == 0) { //check if the given record/data is already a member of not
		if (D->NodeArray[val].stud.IDen == EMPTY || D->NodeArray[val].stud.IDen == DELETED) { /* check if the index is EMPTY OR DELETED */
			D->NodeArray[val].stud.IDen = Rec.IDen; /* if it is EMPTY or DELETED we can insert the given record/data */
		} else { /* if the index you want to insert is not empty or deleted, then the data will be inserted in a next available index*/
			temp = D->avail; /*temp gets the available index*/
			D->avail = D->NodeArray[temp].link; /*available list will traverse to the next link to indicate that it is the next available index*/
			D->NodeArray[temp].stud.IDen = Rec.IDen; /*gets the given ID in a record*/ 
			D->NodeArray[temp].link = D->NodeArray[val].link; /*the temp index points to val or Insert first*/
			D->NodeArray[val].link = temp; /*link point to temp*/
		}
	}
}
void deleteElement(Dictionary *D, studrec Rec)
{
	int val, member, temp, *trav;
	
	val = Hash(Rec.IDen);
	member = isMember(*D,Rec.IDen,val);
	
	if (member == 1) {
		if (D->NodeArray[val].stud.IDen != DELETED && D->NodeArray[val].stud.IDen == Rec.IDen) {
			D->NodeArray[val].stud.IDen == DELETED;
		} else {
			for (trav = &D->NodeArray[val].link; *trav != -1 && D->NodeArray[val].stud.IDen != Rec.IDen; trav = &D->NodeArray[*trav].link) {}
			
			temp = *trav;
			*trav = D->NodeArray[temp].link;
			D->NodeArray[temp].link = D->avail;
			D->avail = temp;
		}
	}
}

void display(Dictionary D) {
	int x;
	int y = SIZE/2;
	for(x=0; x<SIZE; x++){
		if(x < y){
			printf("\n[%d] == Elem: [%d]  Link: [%d]\n",x, D.NodeArray[x].stud.IDen, D.NodeArray[x].link);
			printf("\t\t\t\t\t[%d] == Elem: [%d]  Link: [%d]\n",x+10, D.NodeArray[x+10], D.NodeArray[x+10].link);
		}
	}	
	printf("\n\n\nAvail: %d", D.avail);
}
