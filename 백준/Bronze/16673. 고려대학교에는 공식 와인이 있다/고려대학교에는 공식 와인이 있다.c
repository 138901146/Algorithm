#include<stdio.h>

int main(void)
{
	int C, K, P;

	scanf("%d %d %d", &C, &K, &P);

	printf("%d\n", K*C*(C+1)/2+P*C*(C+1)*(2*C+1)/6);

	return 0;
}