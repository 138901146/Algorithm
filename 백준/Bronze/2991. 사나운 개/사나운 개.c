#include<stdio.h>

int main(void)
{
	int A, B, C, D, P, M, N;

	scanf("%d %d %d %d", &A, &B, &C, &D);
	scanf("%d %d %d", &P, &M, &N);

	printf("%d\n", (P%(A+B)<=A&&P%(A+B)>0)+(P%(C+D)<=C&&P%(C+D)>0));
	printf("%d\n", (M%(A+B)<=A&&M%(A+B)>0)+(M%(C+D)<=C&&M%(C+D)>0));
	printf("%d\n", (N%(A+B)<=A&&N%(A+B)>0)+(N%(C+D)<=C&&N%(C+D)>0));
	return 0;
}