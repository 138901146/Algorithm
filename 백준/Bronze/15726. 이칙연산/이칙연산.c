#include<stdio.h>

int main(void)
{
	long long A, B, C;

	scanf("%lld%lld%lld", &A, &B, &C);

	printf("%lld", A*C/B<A*B/C?A*B/C:A*C/B);
	return 0;
}