#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int a, b, mul=1;

		scanf("%d%d", &a, &b);

		while(b--)
			mul=mul*a%10;

		printf("%d\n", mul?mul:10);
	}

	return 0;
}