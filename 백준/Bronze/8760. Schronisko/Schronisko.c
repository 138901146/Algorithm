#include<stdio.h>

int main(void)
{
	int Z, W, K;

	scanf("%d", &Z);

	while(Z--)
	{
		scanf("%d%d", &W, &K);
		printf("%d\n", W*K-((W&K)&1)>>1);
	}

	return 0;
}