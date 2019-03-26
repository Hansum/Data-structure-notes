#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef int SET[SIZE];

void unionSort(SET A, SET B);
void display(SET C);

int main()
{
	//SET A = {1,3,4,8};
	SET A = {1,0,1,1,0,0,0,1};
	//SET B = {2,5,6,7};
	SET B = {0,1,0,0,1,1,1};
	unionSort(A,B);
	return 0;
}

void unionSort(SET A, SET B)
{
	SET *C, temp;
	int i=0;
	C = (SET *)malloc(sizeof(SET)*SIZE);
	while(i<SIZE)
	{
		if(A[i]==1 || B[i]==1)
		{
			(*C)[i]=1;
		}else{
			(*C)[i]=0;
		}
		i++;
		printf("C[%d]: %d",i,C[i]);
	}
}
