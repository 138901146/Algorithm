#include<stdio.h>

int main(void)
{
	int T;
	long long N;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%lld", &N);
		printf("%lld\n", N*N);
	}

	return 0;
}