#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	printf("%s!", A+B==C?"correct":"wrong");
	return 0;
}