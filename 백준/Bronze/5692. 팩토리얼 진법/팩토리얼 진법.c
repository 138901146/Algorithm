#include<stdio.h>

int main(void)
{
	int x;

	scanf("%d", &x);

	while(x)
	{
		int decimal=0, i=0, factorial=1;

		while(x)
		{
			factorial*=++i;
			decimal+=(x%10)*factorial;
			x/=10;
		}

		printf("%d\n", decimal);
		scanf("%d", &x);
	}

	return 0;
}