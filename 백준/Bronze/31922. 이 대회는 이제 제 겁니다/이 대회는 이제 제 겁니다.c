#include<stdio.h>

int main(void)
{
	int A, P, C;

	scanf("%d%d%d", &A, &P, &C);

	printf("%d", A+C<P?P:A+C);
	return 0;
}