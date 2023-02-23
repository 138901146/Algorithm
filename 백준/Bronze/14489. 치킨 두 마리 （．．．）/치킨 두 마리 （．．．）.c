#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", A+B>=2*C?A+B-2*C:A+B);
	return 0;
}