#include<stdio.h>

int main(void)
{
	int n, c, p;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d%d", &c, &p);
		printf("%d %d\n%d\n", c, p, p+(p-2)*(c-1));
	}

	return 0;
}