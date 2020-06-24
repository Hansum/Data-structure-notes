#include <stdio.h>
#include <stdlib.h>
#define SIZE 18
#define HASH_SIZE 7


/* Data structure Definition */
typedef  short  int  compWordSet;      /* Computer Word implementation of set */
typedef int setBitVector[SIZE];        /* Bit-vector implementation of set    */
   
/*Definition of Set and Dictionary */
typedef struct {
	unsigned int ID;
	char FN[24], LN[16], MI;
}student;

typedef struct node {
	student stud;
	struct node *link;
}ctype, *studSet;

typedef struct openD {
  studSet hashTable[HASH_SIZE];
  int ctr;   /*# of elements in the dictionary */
}*Dictionary;



/* PROBLEMS with function Prototypes */
/*****************************************************************************************
 * Problem 1: a) function displayBitPattern() is a platform independent function that    *
 *               will display the bit pattern of a given number                          * 
 *            b) function dislaySetElements() will display the elements of the set in    *
 *               descending order.                                                       * 
 ******************************************************************************************/
void displayBitPattern(compWordSet S);  
void displaySetElements(compWordSet S, char nameOfSet);  
 
/*******************************************************************************************
 * Problem 2:   Given a set implemented in memory using computer word, function            *
 *     createBitVec() is a the platform-independent function that will create an           *
 *     equivalent set in Bit-Vector implementation.  The function will return the new set  *
 *     to the calling function.                                                            *  
 *******************************************************************************************/
setBitVector * createBitVec(compWordSet S);
void displayBitVector(setBitVector V);        /* Function is provided */
 
/*******************************************************************************************
 * Problem 3:                                                                               *
 *       a)	findHashVal().  Given the student record, the hash function returns the hash    *
 *          value which is the sum of all the 1's in the binary representation of the ID    *
 *          number.  If the  sum exceeds the table size, the sum is divided by the table    *
 *          size and the remainder is returned as the hash value.  
 *       b) convertToDic(). The function will convert a given SET of student records into  *
 *          a dictionary of student records. Each group is sorted in ascending order        *
 *          according to last name. The newly created dictionary will be returned  to the   *
 *          calling function.                                                               *
  *******************************************************************************************/ 
 int findHashVal(student S);
 studSet populateLinkedSet();              /* Function is Provided */
 void displaySet(studSet L);               /* Function is Provided */
 Dictionary convertToDic(studSet *L);
 void displayDictionary(Dictionary D);     /* Function is Provided */
 
 
int main()
{
	compWordSet  A = -215;      /* A = { 15, 14, 13, 12, 11, 10, 9, 8, 5, 3, 0 }  */
   compWordSet  B =  73;      /*  B = { 6, 3, 0 } */
   studSet set;
   Dictionary dict;
   setBitVector *c;
 
	
	printf("\n\nProblem 1: Bit Pattern and Elements of the set");
	/* Call displayBitPattern twice for sets A and B,
	 * Call displaySetElements twice for sets A and B */
	 printf("\nBit pattern of A:\n");
	 displayBitPattern(A);
	 printf("\nBit pattern of B:\n");
	 displayBitPattern(B);
	 printf("\nSet element of A\n");
	 displaySetElements(A,'a');
	 printf("\nSet element of B\n");
	 displaySetElements(B,'b');

	
	printf("\n\nProblem 2: Bit Vector");
   /* Call createBitVec() passing compWordSet A,then
	 * call displayBitVector().  
	*/
	
	c = createBitVec(A);
	displayBitVector(c);
	
	printf("\n\nProblem 3: Dictionary");
	/* Call populateLinkedList(), 
	   call convertToDic(), then displayDictionary().  
	*/
	
	set = populateLinkedSet();
	displaySet(set);
	dict = convertToDic(&set);
	displayDictionary(dict);
	
		
	 return 0;
         
}

/*******************************************************
 * PROBLEM 1 Functions                                  *
 *******************************************************/

 
 
void displayBitPattern(compWordSet S) {
	unsigned int mask, size;
	
	size = sizeof(compWordSet)*8;
	
	for (mask = 1<<size-1; mask != 0; mask >>=1) {
		if((S&mask) != 0) {
			printf("1");
		}else {
			printf("0");
		}
	}
}
void displaySetElements(compWordSet S, char nameOfSet) {
	unsigned int mask, size;
	int i;
	
	size = sizeof(compWordSet)*8;
	mask = 1<<size-1;
	
	for (i = size - 1; mask != 0; mask>>=1, i--) {
		if((S&mask) != 0) {
			printf("%d ",i);
		}
	}
}

/*******************************************************
 * PROBLEM 2 Functions                                  *
 *******************************************************/
 
setBitVector * createBitVec(compWordSet S) {
 	setBitVector *D;
 	unsigned int mask, size,i;
 	
 	size = sizeof(compWordSet)*9;
 	
/* 	D = (setBitVector *)malloc(sizeof(int)*4); */

 	mask = 1 << size - 1;
 	
 	for (i = size - 1; mask !=0; mask >>=1,i--) {
 		(*D)[i] = ((mask&S) != 0) ? 1 : 0;
	}
	return D;
 }
void displayBitVector(setBitVector V)
{
	int x;
	
	printf("\n%10s:", "Index");
	for(x = 0; x < SIZE; x++){
		printf("%4d", x);
	}
	printf("\n%10s:", "Elements");
	
	for(x = 0; x < SIZE; x++){
		printf("%4d", V[x]);
	}
}

/*******************************************************
 * PROBLEM 3 Functions                                  *
 *******************************************************/
 studSet populateLinkedSet()
 {
 	 student S[10] = { 	{121010, "Jane", "Jumalon", 'J'}, { 121016 , "Paul", "Perez", 'P'},
                        {121005, "Elaine", "Englis", 'E'}, { 121008, "Holly", "Hernandez", 'H'},
							   {121001, "Abel", "Ang", 'A'}, {121023, "Fe", "Flores", 'F'},
								{121013, "Manny", "Mendoza", 'M'}, {121007, "Gwen", "Go", 'G'},
							   {121019, "Susie", "Suson", 'S'}, {121003, "Carl", "Conan", 'C'}
								};
	 studSet L, *p;
	 int x;
	 L = NULL; 
	 p = &L;
	 for(x = 0; x < 10; x++) {
	 	 *p = (studSet)malloc(sizeof(ctype));
	 	 if (*p != NULL){
	 	 	(*p)->stud = S[x];
	  	 	p = &(*p)->link;
	 	  }
	 }
	 *p = NULL;
    return L;	   
 }

 void displaySet(studSet S)
 {
 	printf("Elements of the Linked Set");
	for ( ; S != NULL; S = S->link){
 		printf("\n%-10d", S->stud.ID);
		printf("%-12s", S->stud.FN);
		printf("%-5c", S->stud.MI);
		printf("%-16s", S->stud.LN);
	}
 }
 
void displayDictionary(Dictionary D)
{
	int x;
	
	printf("\n\nElements of the Dictionary");
	for(x = 0 ; x < HASH_SIZE; x++){
		printf("\n\n%d ::  ", x);
		displaySet(D->hashTable[x]);
	}
}

/****** FINDHASHVAL()******/
int findHashVal(student S) {
	int sum = 0;
	unsigned int mask, size;
	
	size = sizeof(int)*8;
	
	for (mask = 1<<size - 1; mask !=0; mask>>=1) {
		if((mask&S.ID) !=0) {
			sum += 1;
		}
	}
	
	return sum % HASH_SIZE;
}

/***** CONVERT TO DIC*****/
Dictionary convertToDic(studSet *L) {
	Dictionary D;
	int i,retval;
	studSet *trav,*trav2, temp;
	
	D = (Dictionary)malloc(sizeof(struct openD));
	
	if(D != NULL) {
		for (i = 0; i <HASH_SIZE; i++) {
			D->hashTable[i] = NULL;
		}
		D->ctr = 0;
		
		for (trav = L; *trav != NULL;) {
			retval = findHashVal((*trav)->stud);
			for (trav2 = &D->hashTable[retval]; *trav2 != NULL && strcmp((*trav)->stud.LN, (*trav2)->stud.LN) > 0; trav2 = &(*trav2)->link) {}
			
			
			if (*trav2 != NULL || *trav2 == NULL) {
				temp = *trav;
				*trav = temp->link;
				temp->link = *trav2;
				*trav2 = temp;
				D->ctr++;
			}
		}
	}
	
	return D;
}

