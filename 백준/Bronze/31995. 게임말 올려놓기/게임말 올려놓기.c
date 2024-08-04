#include<stdio.h>

int main(void)
{
	int N, M;

	scanf("%d", &N);
	scanf("%d", &M);

	printf("%d", ((N-1)*(M-1))<<1);
	return 0;
}