#include <stdio.h>
#include <conio.h>
#define SIZE 8

void displayBit(int data);

int main()
{
	int elem;
	
	printf("Enter a number: ");
	scanf("%d",&elem);
	displayBit(elem);
	
	return 0;
}

void displayBit(int data)
{
//	if(data>1)
//	{
//		displayBit(data/2);
//	}
//	printf("%d",data%2);
	int temp,size,numshift,choice;
	size = 8;
	printf("Select a number: 1 - Display Bit pattern, 2 - right shift, 3 - Left shift: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("BIT PATTERN OF %d\n",data);
			while(size>0)
			{
				temp = data >> size;
//				printf("temp value: %d\n",temp);
				if(temp & 1)
				{
					printf("1");
				}else{
					printf("0");
				}
				size--;
			}
		break;
		case 2:
			printf("Enter number to shift:");
			scanf("%d",&numshift);
			temp = data >> numshift;
			printf("Right shift: %d",temp);
		break;
		case 3:
			printf("Enter number to shift:");
			scanf("%d",&numshift);
			temp = data << numshift;
			printf("Right shift: %d",temp);
		break;
		default:
			printf("Choice not found");
	}
	
	
	
}
