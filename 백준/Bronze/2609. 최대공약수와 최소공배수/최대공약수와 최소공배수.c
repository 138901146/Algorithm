#include<stdio.h>

int gcd_euclid(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	while(y!=0)
	{
		int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int num1, num2, gcd;

	scanf("%d %d", &num1, &num2);

	gcd=gcd_euclid(num1,num2);

	printf("%d\n%d\n", gcd, (num1*num2)/gcd);

	return 0;
}