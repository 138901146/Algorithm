#include<stdio.h>

int main(void)
{
	int M, N, K, count=0;

	scanf("%d %d %d", &N, &M, &K);

	while(N+M-3*count>=K && M>=count && N>=2*count)
		count++;

	printf("%d\n", count-1);
	return 0;
}