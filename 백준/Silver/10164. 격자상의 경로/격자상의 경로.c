#include<stdio.h>

int main(void)
{
	int N, M, K, grid[16][16]={0}, r=0, c=0;

	scanf("%d%d%d", &N, &M, &K);

	grid[1][1]=1;
	if(K)
	{
		r=(K-1)/M+1;
		c=K%M;
		if(!c)
			c+=M;

		for(int n=1;n<=r;++n)
			for(int m=1;m<=c;++m)
				grid[n][m]+=grid[n-1][m]+grid[n][m-1];

		for(int n=r+1;n<=N;++n)
			grid[n][c]=grid[r][c];
		for(int m=c+1;m<=M;++m)
			grid[r][m]=grid[r][c];
	}

	for(int n=r+1;n<=N;++n)
		for(int m=c+1;m<=M;++m)
			grid[n][m]+=grid[n-1][m]+grid[n][m-1];

	printf("%d", grid[N][M]);
	return 0;
}