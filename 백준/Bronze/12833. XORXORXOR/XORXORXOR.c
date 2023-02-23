#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	for(int c=0;c<C%2;c++)
		A^=B;

	printf("%d\n", A);
	return 0;
}