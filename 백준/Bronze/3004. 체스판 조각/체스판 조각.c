#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d\n", (N/2+1)*(N-N/2+1));
	return 0;
}