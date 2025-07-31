#include<stdio.h>

int main(void)
{
	int N, B, recover[3000], max[3001][2][2]={0}, current=0, previous=1, best=0;

	scanf("%d%d", &N, &B);

	for(int n=0;n<N;++n)
		scanf("%d", &recover[n]);

	for(int n=1;n<N;++n)
	{
		for(int b=0;b<B-1;++b)
		{
			max[b][current][0]=max[b][previous][0]<max[b][previous][1]?max[b][previous][1]:max[b][previous][0];
			max[b][current][1]=max[b+1][previous][0]<max[b+1][previous][1]+recover[n]?max[b+1][previous][1]+recover[n]:max[b+1][previous][0];
			best=max[b][current][0]<best?best:max[b][current][0];
			best=max[b][current][1]<best?best:max[b][current][1];
		}

		previous^=1;
		current^=1;
	}

	printf("%d", best);
	return 0;
}