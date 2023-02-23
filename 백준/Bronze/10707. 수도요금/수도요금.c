#include<stdio.h>

int main(void)
{
	int A, B, C, D, P;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);
	scanf("%d", &P);

	A*=P;
	B=P<C?B:B+D*(P-C);

	printf("%d\n", A<B?A:B);

	return 0;
}