#include<stdio.h>

int main(void)
{
	long long N, M;

	scanf("%lld%lld", &N, &M);

	printf("%lld", N*M>>1);
	return 0;
}