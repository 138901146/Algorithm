#include<stdio.h>

int main(void)
{
	int n, X, Y;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d%d", &X, &Y);
		printf("%s BRAINS\n", X<Y?"NO":"MMM");
	}

	return 0;
}