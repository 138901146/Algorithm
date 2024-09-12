#include<stdio.h>

int main(void)
{
	int X, count=0;

	scanf("%d", &X);

	while(9<X)
	{
		int mul=1;

		while(X)
		{
			mul*=X%10;
			X/=10;
		}

		X=mul;
		++count;
	}

	printf("%d", count);
	return 0;
}