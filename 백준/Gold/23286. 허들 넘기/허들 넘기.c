#include<stdio.h>

#define INF 1234567

int max(int x,int y)
{
	return x<y?y:x;
}

int distance[301][301];

int main(void)
{
	int N, M, T, u, v, h, s, e;

	scanf("%d%d%d", &N, &M, &T);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			distance[i][j]=INF;
		distance[i][i]=0;
	}

	while(M--)
	{
		scanf("%d%d%d", &u, &v, &h);
		distance[u][v]=h;
	}

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				if(max(distance[start][mid],distance[mid][end])<distance[start][end])
					distance[start][end]=max(distance[start][mid],distance[mid][end]);

	while(T--)
	{
		scanf("%d%d", &s, &e);
		printf("%d\n", distance[s][e]==INF?-1:distance[s][e]);
	}

	return 0;
}