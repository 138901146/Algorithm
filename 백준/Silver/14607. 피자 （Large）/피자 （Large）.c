#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%lld", (long long)N*(N-1)>>1);
	return 0;
}