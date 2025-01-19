#include<stdio.h>

int main(void)
{
	int N, K;

	scanf("%d%d", &N, &K);

	while(--N)
		K>>=1;

	printf("%d", K);
	return 0;
}