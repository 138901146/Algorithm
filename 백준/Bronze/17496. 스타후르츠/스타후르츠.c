#include<stdio.h>

int main(void)
{
	int N, T, C, P;

	scanf("%d %d %d %d", &N, &T, &C, &P);

	printf("%d\n", C*P*((N-1)/T));
	return 0;
}