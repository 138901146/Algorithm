#include<stdio.h>

int main(void)
{
	long long N, M, A;

	scanf("%lld", &N);
	A=-N*(N-1)>>1;

	while(N--)
	{
		scanf("%lld", &M);
		A+=M;
	}

	printf("%lld", A);
	return 0;
}