#include<stdio.h>

int main(void)
{
	int N, cost[1000][3], sum[1000][3], INF=1000000000, min=INF;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		for(int j=0;j<3;++j)
			scanf("%d", &cost[i][j]);

	for(int primary=0;primary<3;++primary)
	{
		for(int i=0;i<3;++i)
			sum[0][i]=INF;
		sum[0][primary]=cost[0][primary];

		for(int i=1;i<N;++i)
			for(int j=0;j<3;++j)
				sum[i][j]=cost[i][j]+(sum[i-1][(j+1)%3]<sum[i-1][(j+2)%3]?sum[i-1][(j+1)%3]:sum[i-1][(j+2)%3]);

		for(int i=1;i<3;++i)
			min=sum[N-1][(primary+i)%3]<min?sum[N-1][(primary+i)%3]:min;
	}

	printf("%d", min);
	return 0;
}