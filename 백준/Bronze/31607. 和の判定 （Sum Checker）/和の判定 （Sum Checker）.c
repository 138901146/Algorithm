#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	printf("%d", A+B==C || A+C==B || B+C==A);
	return 0;
}