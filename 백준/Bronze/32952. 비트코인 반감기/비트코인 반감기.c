#include<stdio.h>

int main(void)
{
	long long R, K, M;

	scanf("%lld%lld%lld", &R, &K, &M);

	M/=K;

	while(R && M--)
		R>>=1;

	printf("%lld", R);
	return 0;
}