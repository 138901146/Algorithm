#include<stdio.h>

int main(void)
{
	int n, number;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &number);
		printf("%d %d\n", number, number);
	}

	return 0;
}