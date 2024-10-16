#include<stdio.h>

int main(void)
{
	int n, d, count=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &d);
		count+=d&1;
	}

	printf("%d", count);
	return 0;
}