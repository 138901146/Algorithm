#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	printf("%d", A<=C&&C<B);
	return 0;
}