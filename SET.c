#include <stdio.h>
#include <conio.h>
#define SIZE 10

typedef int SET[SIZE];

int unionSort(SET A, SET B);

int main()
{
	int i;
	SET A = {1,1,0,1,0,0,1,0,1,0};
	SET B = {1,0,0,1,0,1,0,0,1,1};
	SET C;

	for(i=0;i<SIZE;i++)
	{
		C[i] = unionSort(A,B);
		printf("C[%d]: %d\n",i,C[i]);
	}
	return 0;
}

int unionSort(SET A, SET B)
{
	int i;
	SET temp;
	for(i = 0;i<SIZE;i++)
	{
		if(A[i]==1||B[i]==1)
		{
			temp[i] = 1;
		}else{
			temp[i] = 0;
		}
		return temp;
	}
}
