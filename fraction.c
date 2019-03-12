#include <stdio.h>

typedef struct
{
	int num;
	int den;
}frac;

void inputFraction(frac *f, frac *l);
void displayDivFraction(frac f);
frac multiplyFraction(frac x, frac y);
frac divideFraction(frac x, frac y);
frac addFraction(frac x, frac y);
frac subtractFraction(frac x, frac y);
int gcd(int x,int y);
void displayMulFraction(frac f);
void displaySubFraction(frac f);
void displayAddFraction(frac f);

int main()
{
	frac x,y,m,d,a,s,g;
	inputFraction(&x,&y);
	printf("\n\nRESULTS:");
	m = multiplyFraction(x,y);
	displayMulFraction(m);
	d = divideFraction(x,y);
	displayDivFraction(d);
	s = subtractFraction(x,y);
	displaySubFraction(s);
	a = addFraction(x,y);
	displayAddFraction(a);
	return 0;
}

//version 1
void inputFraction(frac *f, frac *l)
{
	printf("Enter first numerator:");
	scanf("%d",&f->num);
	printf("\nEnter first denominator:");
	scanf("%d",&f->den);
	printf("\nEnter second numerator:");
	scanf("%d",&l->num);
	printf("\nEnter second denominator:");
	scanf("%d",&l->den);
}

frac multiplyFraction(frac x, frac y)
{
	frac c;
	c.num = x.num * y.num;
	c.den = x.den * y.den;
	return c;
}

frac divideFraction(frac x, frac y)
{
	frac c;
	c.num = x.num * y.den;
	c.den = x.den * y.num;
	
	return c;
}
frac addFraction(frac x, frac y)
{
	frac c;
	c.num = (x.num*y.den) + (x.den*y.num);
	c.den = x.den * y.den;
	
	return c;
}
frac subtractFraction(frac x, frac y)
{
	frac c;
	c.num = (x.num * y.den) - (x.den*y.num);
	c.den = x.den * y.den;
	return c;
}

int gcd(int a,int b)
{

	if (b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}  
      
}


void displayMulFraction(frac f)
{
	printf("\nthe Multiplication fraction is: %d / %d and its simplest form: %d / %d\n", f.num,f.den,f.num/gcd(f.num,f.den),f.den/gcd(f.num,f.den));
}
void displayDivFraction(frac f)
{
	printf("the Divided fraction is: %d / %d and its simplest form: %d / %d\n", f.num,f.den,f.num/gcd(f.num,f.den),f.den/gcd(f.num,f.den));
}
void displaySubFraction(frac f)
{
	printf("the Subtracted fraction is: %d / %d and its simplest form: %d / %d\n", f.num,f.den,f.num/gcd(f.num,f.den),f.den/gcd(f.num,f.den));
}
void displayAddFraction(frac f)
{
	printf("the Added fraction is: %d / %d and its simplest form: %d / %d\n", f.num,f.den,f.num/gcd(f.num,f.den),f.den/gcd(f.num,f.den));
}

