#include<stdio.h>

int main(void)
{
	int P, Q, A, B;

	scanf("%d%d", &P, &Q);
	scanf("%d%d", &A, &B);

	printf("%d", Q<P?Q*A:P*A+(Q-P)*B);
	return 0;
}