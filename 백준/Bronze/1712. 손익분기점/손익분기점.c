#include<stdio.h>

int main(void)
{
	long long int A, B, C, BreakEvenPoint=0;

	scanf("%lld %lld %lld", &A, &B, &C);

	BreakEvenPoint=B>=C?-1:A/(C-B)+1;
	printf("%lld\n", BreakEvenPoint);

	return 0;
}