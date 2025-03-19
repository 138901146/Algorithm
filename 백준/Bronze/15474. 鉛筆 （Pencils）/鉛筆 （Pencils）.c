#include<stdio.h>

int main(void)
{
	int N, A, B, C, D, X, Y;

	scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);

	X=B*(N%A?N/A+1:N/A);
	Y=D*(N%C?N/C+1:N/C);

	printf("%d", X<Y?X:Y);
	return 0;
}