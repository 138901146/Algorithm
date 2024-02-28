#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n)
	{
		printf("%d\n", (n+1)*n>>1);
		scanf("%d", &n);
	}

	return 0;
}