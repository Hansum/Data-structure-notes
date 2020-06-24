#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 8

typedef int SET[SIZE];

void bit(SET A, SET B);


int main()
{
	//SET A = {1,3,4,8};
	SET A = {1,0,1,1,0,0,0,1};
	//SET B = {2,6,7};
	SET B = {0,1,0,0,0,1,1,1};
	bit(A,B);
	return 0;
}

void bit(SET A, SET B)
{
	SET *C, temp;
	int i=0;
	C = (SET *)malloc(sizeof(SET)*SIZE);
	while(i<=SIZE)
	{
		if(A[i] | B[i])
		{
			(*C)[i]=1;
		}else{
			(*C)[i]=0;
		}
		printf("C[%d]: %d\n",i,(*C)[i]);
		i++;
	}
}
