#include<stdio.h>

long long grid[1025][1025]={0};

int main(void)
{
	int N, M, K, x1, x2, y1, y2;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n)
		for(int m=1;m<=M;++m)
		{
			scanf("%lld", &grid[n][m]);
			grid[n][m]+=grid[n-1][m]+grid[n][m-1]-grid[n-1][m-1];
		}

	scanf("%d", &K);

	while(K--)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%lld\n", grid[x2][y2]-grid[x1-1][y2]-grid[x2][y1-1]+grid[x1-1][y1-1]);
	}

	return 0;
}