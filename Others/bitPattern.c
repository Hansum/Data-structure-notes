#include <stdio.h>
#include <conio.h>

typedef char SET;

SET insert(SET *A, int elem);
SET deleteSET(SET *A, int elem);
SET difference(SET A, SET B);
void member(SET A, int elem);
SET unionSet(SET *A, SET B);
SET intersect(SET A, SET B);
void display(SET A);
void displayValue(SET X);

int main()
{
	SET A =43; /*Binary of 43 = 0011011*/
	SET B = 55; /*Binary of 55 = 0001010 */
	SET C;
	SET D;
	SET E;
	SET F;
	int elem =4;
	
	printf("SET A bit pattern: \n");
	display(A);
	printf("{");
	displayValue(A);
	printf("}");
	printf(" == %d",A);
	
	printf("\n");
	
	printf("SET B bit pattern: \n");
	display(B);
	printf("{");
	displayValue(B);
	printf("}");
	printf(" == %d",B);
	
	printf("\n");
	
	//member
	member(A,4);
	
	printf("\n");
	
	//intersect
	printf("Intersect of A and B: \n");
	C = intersect(A,B);
	display(C);
	printf("\n");
	printf("Place value of Intersect A and B is: \n");
	printf("{");
	displayValue(C);
	printf("}");
	printf(" == %d",C);
	
	printf("\n");
	
	printf("The difference of A to B or A-B: \n");
	D = difference(A,B);
	display(D);
	printf("{");
	displayValue(D);
	printf("}");
	printf(" == %d",D);
	
	printf("\n");
	
	//insertion
	printf("Insert:");
	E = insert(&A,elem);
	display(E);
	printf("{");
	displayValue(E);
	printf("}");
	printf(" == %d",E);
	
	printf("\n");
	
	//deletion
	printf("Delete:");
	F = deleteSET(&A,3);
	display(F);
	printf("{");
	displayValue(F);
	printf("}");
	printf(" == %d",F);
//	printf("\n");
	
	return 0;
}

/*insert an element base from the given number of shifts, 
 use bitwise or | to check if the element is available for insertion
 ex: 1 | 0 = 1
*/
SET insert(SET *A, int elem)
{
	SET temp;
	temp =  *A |= 1<<elem;
	return temp;
}

/*
-Delete an element fromt the given number of shifts
-use XOR ^ to make an element false
-ex: 1 ^ 1 = 0
*/
SET deleteSET(SET *A, int elem)
{
	SET temp;
	temp = *A & ~(1<<elem);
	return temp;
}

SET difference(SET A, SET B)
{
	SET temp;
	temp = A &~(B);
	return temp;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}

void member(SET A, int elem)
{
	((A & 1<<elem)!=0) ? printf("%d is a member", elem): printf("%d is not a member", elem);
}

SET unionSet(SET *A, SET B)
{
	SET temp;
	*A |= B;
}

SET intersect(SET A, SET B)
{
	SET temp;
	temp = A & B;
	return temp;
}

void displayValue(SET X)
{
//	int i,sum;
//	for(i=0;A&(1<<i)!=0;i++)
//	{
//		printf("Place holder: %d",pow[i]);
//	} 

	int mask,i;
	unsigned int size;
	size = sizeof(SET)*8;
	
	for(i=size-1,mask=1<<size-1;mask!=0;mask>>=1,i--){
		if((X&mask)!=0)
		{
			printf("%d,",i);
		}
	}
	                                           
}

void display(SET A)
{
	int mask;
	unsigned int size;
	size = sizeof(SET)*8;
	
	for(mask = 1<<size-1;mask!=0;mask>>=1){
		printf("%d",(A&mask)==0?0:1);
	}
}
