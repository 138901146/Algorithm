#include<stdio.h>

int main(void)
{
	int N, M, order, wait[1001], friend, count=0;

	scanf("%d%d", &N, &M);

	for(int i=1;i<=N;++i)
	{
		scanf("%d", &order);
		wait[order]=i;
	}

	for(int i=0;i<M;++i)
	{
		scanf("%d", &friend);
		count+=M<wait[friend];
	}

	printf("%d", count);
	return 0;
}