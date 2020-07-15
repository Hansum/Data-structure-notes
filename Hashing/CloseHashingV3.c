/* CLOSE HASHING VARARTION VERSION 3*/





#include <stdio.h>
#include <conio.h>
#define SIZE 20
#define EMPTY '@'
#define DELETED '$'




typedef struct {
	char data;
	int link;
}Dict;

typedef struct {
	Dict Darray[SIZE];
	int avail;
}Dictionary;


void initDictionary(Dictionary *D);
void insertDictionary(Dictionary *D, char elem);
void display(Dictionary D);
void deleteDictionary(Dictionary *D, char elem);
int hash(char elem);

int main(void) {
	Dictionary d;
	
	initDictionary(&d);
	
	insertDictionary(&d,'d');
	insertDictionary(&d,'e');
	insertDictionary(&d,'f');
	insertDictionary(&d,'g');
	insertDictionary(&d,'h');
	insertDictionary(&d,'i');
	insertDictionary(&d,'j');
	insertDictionary(&d,'k');
	insertDictionary(&d,'l');
	insertDictionary(&d,'m');
	insertDictionary(&d,'a');	
	printf("Avail = %d\n",d.avail);
	
	display(d);
	
	return 0;
}

int hash(char elem) {
	return elem % 10;
}

void initDictionary(Dictionary *D) {
	int prime,ndx, ndx2;
	
	prime = SIZE / 2;
	
	for (ndx = 0; ndx < prime; ndx++) {
		D->Darray[ndx].data = EMPTY;
	}
	
	for (ndx2 = ndx; ndx2 < SIZE-1; ndx2++) {
		D->Darray[ndx2].link = ndx2 + 1;
	}
	
	D->Darray[SIZE-1].link = -1;
	D->avail = SIZE / 2;
	
}

void insertDictionary(Dictionary *D, char elem) {
	int retval, *trav, *trav2;
	
	retval = hash(elem);
	
	if (D->Darray[retval].data == EMPTY || D->Darray[retval].data == DELETED) {
		D->Darray[retval].data = elem;
		D->Darray[retval].link = -1;
	} else {
		if (D->avail != -1) {	
		
		trav = &D->avail;
		trav2 = &D->Darray[retval].link;
		
		D->Darray[*trav].data = elem;
		D->Darray[*trav].link = *trav2;
		D->Darray[*trav2].link = *trav;
		D->avail = D->Darray[*trav].link;
		}
	}
}

void deleteDictionary(Dictionary *D, char elem) {
	int retval, *trav;
	
	retval = hash(elem);
	
	if (D->Darray[retval].data == elem) {
		D->Darray[retval].data = DELETED;
	} else {
		for (trav = &D->Darray[retval].link; *trav != -1 && D->Darray[*trav].data != elem; trav = &D->Darray[*trav].link) {}
		
		if (*trav != -1 && D->Darray[*trav].data == elem) {
			D->Darray[*trav].link = D->avail;
			D->avail = *trav;
		}
	}
}


void display(Dictionary D) {
	int retval, ndx;
	
	for (ndx = 0; ndx < SIZE; ndx ++) {
		printf("[%d] Elem: %c Link: %d\n",ndx,D.Darray[ndx].data,D.Darray[ndx].link);
	}
}


