#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	printf("%c", (A==B||A==C||B==C||A+B==C||A+C==B||B+C==A)?'S':'N');
	return 0;
}