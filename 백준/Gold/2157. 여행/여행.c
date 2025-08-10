#include<stdio.h>

#define INF 99999999

int main(void)
{
	int N, M, K, a, b, c, route[301][301], max[301][301], best=0;

	for(int i=0;i<301;++i)
		for(int j=0;j<301;++j)
			route[i][j]=max[i][j]=-INF;
	max[1][1]=0;

	scanf("%d%d%d", &N, &M, &K);

	while(K--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a<b&&route[a][b]<c)
			route[a][b]=c;
	}

	for(int m=2;m<=M;++m)
		for(int i=1;i<N;++i)
			for(int j=i+1;j<=N;++j)
				if(max[j][m]<max[i][m-1]+route[i][j])
					max[j][m]=max[i][m-1]+route[i][j];

	for(int m=1;m<=M;++m)
		best=max[N][m]<best?best:max[N][m];
	printf("%d", best);
	return 0;
}