#include<stdio.h>

int main(void)
{
	unsigned long long N;
	int K=64;

	scanf("%llu", &N);

	while(!(N&1))
	{
		N>>=1;
		--K;
	}

	printf("%d", K);
	return 0;
}