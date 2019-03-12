#include <stdio.h>
#include <conio.h>
#include <math.h>
//void pt1(int *n)
//{
//	printf("\nEnter the new value for x:");
//	scanf("%d",n);
//	
//}
//
//
//
//int main()
//{
//	int x;
//	printf("Enter the value of x:");
//	scanf("%d",&x);
//	printf("Original value of x = %d\n",x);
//	pt1(&x);
//	printf("\nThe new value of x = %d\n", x);
//	return 0;
//}
//

//int main()
//{
//	int i,a=6,b=0;
//	for(i=0;i<=6;i++)
//	{
//		b += a;
//		printf("%d ",b);
//	}
//	return 0;
//}



/*SWAP FUNCTION*/
 /* *var1 stores the address of num1 while *var2 stores the address of num2*/
//void swapnum ( int *var1, int *var2 )
//{
//   int tempnum ;
//   /*tempnum stores the value of var1*/
//   tempnum = *var1 ;
//   /*var1 stores the value of var2*/
//   *var1 = *var2 ;
//   /*var2 stores the value of tempnum*/
//   *var2 = tempnum ;
//}
//int main( )
//{
//   int num1, num2 ;
//   /*stores value in num1*/
//   printf("\nEnter num1:");
//   scanf("%d",&num1);
//   /*stores value in num2*/
//   printf("\nEnter num2:");
//   scanf("%d",&num2);
//
//   /*calling swap function*/
//   /* &num1 stores the address of num1 and &num2 stores the address of num2*/
//   swapnum( &num1, &num2 );
//
//   printf("\nAfter swapping:");
//   printf("\nnum1 value is %d", num1);
//   printf("\nnum2 value is %d", num2);
//   return 0;
//}

//void salaryhike(int  *var, int b)
//{
//    *var = *var+b;
//}
//int main()
//{
//    int salary=0, bonus=0;
//    printf("Enter the employee current salary:"); 
//    scanf("%d", &salary);
//    printf("Enter bonus:");
//    scanf("%d", &bonus);
//    salaryhike(&salary, bonus);
//    printf("Final salary: %d", salary);
//    return 0;
//}




int GCF(int x, int y)
{
	if(x==0){
		return y;
	}else{
	return GCF(y%x,x);
	}
}

void PRIME(int n)
{
	int i;
	while(n%2==0){
		printf("%d",2);
		n = n/2;
	}
	
	for(i=3;i<=sqrt(n);i=i+2){
		while(n%i==0){
			printf("%d",i);
			n=n/i;
		}
	}
	if(n>2){
		printf("%d",n);
	}
}

int main()
{
	int a,b;
	printf("FIRST FRACTION\n");
	printf("Enter first number:");
	scanf("%d",&a);
	printf("\SECOND FRACTION");
	printf("Enter first number:");
	scanf("%d",&c);
	printf("\nEnter second number:");
	scanf("%d",&d);
	LCD(a,b,c,d);
	PRIME(a);
	
	
	
}
