#include<stdio.h>

int main(void)
{
	int A, B, C, D, E;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);
	scanf("%d", &E);

	if(A<=0)
		printf("%d\n", -A*C+D+B*E);
	else
		printf("%d\n", E*(B-A));

	return 0;
}