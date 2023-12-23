#include<stdio.h>

long long factorial(int current)
{
	return current<2?1:current*factorial(current-1);
}

int main(void)
{
	int N, A, B, C;

	scanf("%d%d%d%d", &N, &A, &B, &C);

	printf("%lld", factorial(N)/(factorial(A)*factorial(B)*factorial(C)));
	return 0;
}