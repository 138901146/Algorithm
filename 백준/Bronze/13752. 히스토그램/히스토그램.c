#include<stdio.h>

int main(void)
{
	int n, k;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &k);

		while(k--)
			printf("=");
		printf("\n");
	}

	return 0;
}