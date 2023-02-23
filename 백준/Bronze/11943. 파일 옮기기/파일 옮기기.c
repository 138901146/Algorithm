#include<stdio.h>

int main(void)
{
	int A, B, C, D;

	scanf("%d %d", &A, &B);
	scanf("%d %d", &C, &D);

	printf("%d\n", A+D<B+C?A+D:B+C);
	return 0;
}