#include<stdio.h>

long long lcm(long long x,long long y)
{
	long long mul=x*y, temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return mul/x;
}

int main(void)
{
	int count;
	long long N=1, A, max=0, min=10000000;

	scanf("%d", &count);

	while(count--)
	{
		scanf("%lld", &A);

		max=A>max?A:max;
		min=A<min?A:min;

		N=lcm(N,A);
	}

	printf("%lld", N==max?N*min:N);
	return 0;
}