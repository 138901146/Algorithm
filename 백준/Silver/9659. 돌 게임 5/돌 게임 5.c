#include<stdio.h>

int main(void)
{
	long long N;

	scanf("%lld", &N);

	printf("%s\n", N&1?"SK":"CY");

	return 0;
}