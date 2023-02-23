#include<stdio.h>

unsigned long long int gcd(unsigned long long int x,unsigned long long int y)
{
	if(x<y)
	{
		unsigned long long int temp=x;
		x=y;
		y=temp;
	}

	while(y!=0)
	{
		unsigned long long int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

unsigned long long int lcm(unsigned long long int x,unsigned long long int y)
{
	return x*y/gcd(x,y);
}

int main(void)
{
	int n;

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		unsigned long long int a, b;

		scanf("%llu %llu", &a, &b);

		printf("%llu\n", lcm(a,b));
	}

	return 0;
}