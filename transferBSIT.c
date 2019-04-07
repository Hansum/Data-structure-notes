//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <string.h>
//#define SIZE 8
//
//typedef int List;
//
//typedef struct node{
//	char data[SIZE];
//	int link;
//}Node;
//
//typedef struct{
//	Node nodeArray[SIZE];
//	int availList;
//}VirtualHeap;
//
//void init(VirtualHeap *H);
//void insertFirst(VirtualHeap *H, List *L,char elem[]);
//void transferBSIT(VirtualHeap *H, List *IT, List *CS,List *A);
//void display(VirtualHeap *H,List *IT, List *CS);
//
//int main()
//{
//	VirtualHeap VH;
//	List i,IT,CS,T;
//	i = IT = CS -1;
//	T = 0;
//	init(&VH);
//	insertFirst(&VH,&i,"BSCS");
//	insertFirst(&VH,&i,"BSIT");
//	insertFirst(&VH,&i,"BSIT");
//	insertFirst(&VH,&i,"BSCS");
//	insertFirst(&VH,&i,"BSCS");
//	insertFirst(&VH,&i,"BSIT");
//	insertFirst(&VH,&i,"BSCS");
//	insertFirst(&VH,&i,"BSIT ");
//	transferBSIT(&VH,&IT,&CS,&T);
//	display(&VH,&IT,&CS);	
//	return 0;
//}
//
//void init(VirtualHeap *H)
//{
//	List i;
//	for(i=SIZE-1;i>-1;i--)
//	{
//		H->nodeArray[i].link = i-1;
//	}
//	H->availList = SIZE-1;
//}
//
//void insertFirst(VirtualHeap *H, List *L,char elem[])
//{
//	List temp;
//	temp = H->availList;
//	if(temp!=-1)
//	{
//		H->availList = H->nodeArray[temp].link;
//		strcpy(H->nodeArray[temp].data,elem);
//		H->nodeArray[temp].link = *L;
//		*L = temp;
//	}
//}
//
//void transferBSIT(VirtualHeap *H,List *IT, List *CS,List *A)
//{
//	List temp, *trav;
//	for(trav = A;*trav!=-1;)
//	{
//		if(strcmp(H->nodeArray[*trav].data,"BSIT")==0)
//		{
//			temp = *trav;
//			*trav = H->nodeArray[temp].link;
//			H->nodeArray[temp].link = *IT;
//			*IT = temp;
//		}else if(strcmp(H->nodeArray[*trav].data,"BSCS")==0){
//			temp = *trav;
//			*trav = H->nodeArray[temp].link;
//			H->nodeArray[temp].link = *CS;
//			*CS = temp;
//		}else{
//			trav = &H->nodeArray[*trav].link;		
//		}
//	}
//			
//}
//
//void display(VirtualHeap *H,List *IT, List *CS)
//{
////	List *trav;
////	for(trav = H;*trav!=-1;trav = &H->nodeArray[*trav].link)
////	{
////		if(strcmp(H->nodeArray[*trav].data,"BSIT")==0){
////			printf("BSIT: %s", H->nodeArray[*trav].data);
////		}else if(strcmp(H->nodeArray[*trav].data,"BSCS")==0)
////		{
////			printf("BSCS: %s",H->nodeArray[*trav].data);
////		}
////	}
//	List *trav, *trav2;
//	for(trav = IT;*trav!=-1;trav = &H->nodeArray[*trav].link)
//	{
//		printf("BSIT: %s", H->nodeArray[*trav].data);
//	}
//	for(trav2 = CS;*trav2!=-1;trav2 = &H->nodeArray[*trav2].link)
//	{
//		printf("BSCS: %s", H->nodeArray[*trav2].data);
//	}
//}
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8

typedef int List;

typedef struct node{
	char data[SIZE];
	int link;
}Node;

typedef struct{
	Node nodeArray[SIZE];
	int availList;
}VirtualHeap;

void init(VirtualHeap *H);
void insertFirst(VirtualHeap *H, List *L,char elem[]);
void transferBSIT(VirtualHeap *H, List *IT, List *CS,List *A);
void display(VirtualHeap H,List IT, List CS);

int main()
{
	VirtualHeap VH;
	List IT,CS,T;
	T = IT = CS -1;
	init(&VH);
	insertFirst(&VH,&T,"BSCS");
	insertFirst(&VH,&T,"BSIT");
	insertFirst(&VH,&T,"BSIT");
	insertFirst(&VH,&T,"BSCS");
	insertFirst(&VH,&T,"BSCS");
	insertFirst(&VH,&T,"BSIT");
	insertFirst(&VH,&T,"BSCS");
	insertFirst(&VH,&T,"BSIT ");	
	transferBSIT(&VH,&IT,&CS,&T);
	display(VH,IT,CS);
	return 0;
}

void init(VirtualHeap *H)
{
	List i;
	for(i=SIZE-1;i>-1;i--)
	{
		H->nodeArray[i].link = i-1;
	}
	H->availList = SIZE-1;
}

void insertFirst(VirtualHeap *H, List *L,char elem[])
{
	List temp;
	temp = H->availList;
	if(temp!=-1)
	{
		H->availList = H->nodeArray[temp].link;
		strcpy(H->nodeArray[temp].data,elem);
		H->nodeArray[temp].link = *L;
		*L = temp;
	}
}

void transferBSIT(VirtualHeap *H,List *IT, List *CS,List *A)
{
	List temp, *trav;
	for(trav = A;*trav!=-1;)
	{
		if(strcmp(H->nodeArray[*trav].data,"BSIT")==0)
		{
			temp = *trav;
			*trav = H->nodeArray[temp].link;
			H->nodeArray[temp].link = *IT;
			*IT = temp;
		}else if(strcmp(H->nodeArray[*trav].data,"BSCS")==0){
			temp = *trav;
			*trav = H->nodeArray[temp].link;
			H->nodeArray[temp].link = *CS;
			*CS = temp;
		}else{
			trav = &H->nodeArray[*trav].link;		
		}
	}
			
}

void display(VirtualHeap H,List IT, List CS)
{
	while(IT!=-1){
		printf("BSIT: %s\n", H.nodeArray[IT].data);
		IT = H.nodeArray[IT].link;
	}
	
	printf("\n\n");
	
	while(CS!=-1){
		printf("BSCS: %s\n", H.nodeArray[CS].data);
		CS = H.nodeArray[CS].link;
	}
}

