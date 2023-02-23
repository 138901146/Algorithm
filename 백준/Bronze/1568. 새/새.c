#include<stdio.h>

int main(void)
{
	int N, K=0, count=0;

	scanf("%d", &N);

	while(N>0)
	{
		K=N>K?K+1:1;
		N-=K;
		count++;
	}

	printf("%d\n", count);
	return 0;
}