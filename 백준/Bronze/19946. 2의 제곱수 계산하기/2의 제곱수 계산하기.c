#include<stdio.h>

int main(void)
{
	unsigned long long int N;
	int K=64;

	scanf("%llu", &N);

	while(N%2==0)
	{
		N/=2;
		K--;
	}

	printf("%d\n", K);
	return 0;
}