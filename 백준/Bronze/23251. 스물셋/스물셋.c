#include<stdio.h>

int main(void)
{
	int T, k;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &k);
		printf("%d\n", k*23);
	}

	return 0;
}