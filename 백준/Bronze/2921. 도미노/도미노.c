#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	printf("%d\n", N*(N+1)*(N+2)/2);
	return 0;
}