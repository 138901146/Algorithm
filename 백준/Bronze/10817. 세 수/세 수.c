#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	if(A<B && A<C)
		printf("%d\n", B<C?B:C);
	else if(B<A && B<C)
		printf("%d\n", A<C?A:C);
	else
		printf("%d\n", A<B?A:B);

	return 0;
}