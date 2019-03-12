#include <stdio.h>

//void main()
//
//{
//
//    int m, n; /* given numbers */
//
//    
//
//    printf("Enter-two integer numbers: ");
//
//    scanf ("%d %d", &m, &n);
//
//    while (n > 0)
//
//    {
//
//        int r = m % n;
//
//        m = n;
//
//        n = r;
//
//    }
//
//    printf ("GCD = %d \n",m);
//
//    getch();
//
//}

int main()
{
	int a,b,hcf,lcm;
	printf("Enter first number:");
	scanf("%d", &a);
	printf("Enter second number:");
	scanf("%d",&b);
	hcf = gcd(a,b);
	lcm = (a*b)/gcd(a,b);;
	printf("GCD = %d", hcf);
	printf("\nLCM = %d", lcm);
}

int gcd(int a, int b)
{
	if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}
