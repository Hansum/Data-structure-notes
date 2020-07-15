#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node {
	int elem;
	struct node *RC;
	struct node *LC;
}*BST;

//typedef enum{TRUE, FALSE}boolean;

void insertBST(BST *T, int data);
int deleteminBST(BST *T);
void display(BST T);
int isMember(BST T, int data);
void initBST(BST *T);
void preOrder(BST T);
void inOrder(BST T);
void postOrder(BST T);
void deleteBST(BST *T, int data);

int main(void) {
	BST tree;
	
	initBST(&tree);
	
	insertBST(&tree,15);
	insertBST(&tree,10);
	insertBST(&tree,5);
	insertBST(&tree,12);
	insertBST(&tree,8);
	insertBST(&tree,20);
	insertBST(&tree,30);
	insertBST(&tree,40);
	insertBST(&tree,31);
	insertBST(&tree,50);
	
	preOrder(tree);
	inOrder(tree);
	postOrder(tree);
	
	return 0;
}

void initBST(BST *T) {
	*T = NULL;
}

void insertBST(BST *T, int data) {
	BST *trav, temp;
	
	for (trav = T; *trav != NULL; ) {
		trav = ((*trav)->elem < data) ? &(*trav)->RC : &(*trav)->LC;
	}
	
	if (*trav == NULL) {
		temp = (BST)malloc(sizeof(struct node));
		
		if (temp!= NULL) {
			temp->elem = data;
			temp->RC = temp->LC = NULL;
			*trav = temp;
		}
		
	}
}

int deleteminBST(BST *T) {
	BST *trav, temp;
	int retval;
	
	for (trav = T; *trav != NULL && (*trav)->LC != NULL; trav = &(*trav)->LC){}
	
	if (*trav != NULL) {
		temp = *trav;
		retval = temp->elem;
		*trav = temp->RC;
		free(temp);
	}
}

void deleteBST(BST *T, int data) {
	int retvalDeletemin;

	BST *trav, temp;
	
	for (trav = T; *trav != NULL && (*trav)->elem != data; ) {
		trav = ((*trav)>elem < data) ? &(*trav)->RC : &(*trav)->LC;
	}
	
	if ((*trav)->LC != NULL && (*trav)->RC != NULL) {
		retval = deleteminBST(&(*trav)->RC);
		(*trav)->elem = retval;
	}else if ((*trav)->LC == NULL && (*trav)->RC != NULL) {
		temp = *trav;
		*trav = temp->LC;
		free(temp);
	}else {
		temp = *trav;
		*trav = temp->RC;
		free(temp);
	}
}

void preOrder(BST T) {
	
	if (T == NULL ) {
		return;
	}
	printf("PRE ORDER: %d\n",T->elem);
	preOrder(T->LC);
	preOrder(T->RC);
}
void inOrder(BST T) {
	
	if (T != NULL ) {
		inOrder(T->LC);
		printf("IN ORDER: %d\n",T->elem);
		inOrder(T->RC);	
	}
	
	
}
void postOrder(BST T) {
	
	if (T == NULL ) {
		return;
	}
	
	postOrder(T->LC);
	postOrder(T->RC);
	printf("POST ORDER: %d\n",T->elem);
}
int isMember(BST T, int data) {
	BST trav;
	
	for (trav = T; trav != NULL && trav->elem != data; ) {
		trav = (trav->elem < data) ? trav->RC : trav->LC;
	}
	
	return (trav != NULL) ?	1 : 0;
}
