#include<stdio.h>

#define INF 12345678

int main(void)
{
	int N, M, A, B, T, distance[201][201], K, C[200], min=INF;

	scanf("%d%d", &N, &M);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			distance[i][j]=INF;
		distance[i][i]=0;
	}

	while(M--)
	{
		scanf("%d%d%d", &A, &B, &T);
		distance[A][B]=distance[A][B]<T?distance[A][B]:T;
	}

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				distance[start][end]=distance[start][mid]+distance[mid][end]<distance[start][end]?distance[start][mid]+distance[mid][end]:distance[start][end];

	scanf("%d", &K);
	for(int i=0;i<K;++i)
		scanf("%d", &C[i]);

	for(int x=1;x<=N;++x)
	{
		int max=0;

		for(int k=0;k<K;++k)
			max=distance[C[k]][x]+distance[x][C[k]]<max?max:distance[C[k]][x]+distance[x][C[k]];

		min=max<min?max:min;
	}

	for(int x=1;x<=N;++x)
	{
		int max=0;

		for(int k=0;k<K;++k)
			max=distance[C[k]][x]+distance[x][C[k]]<max?max:distance[C[k]][x]+distance[x][C[k]];

		if(max==min)
			printf("%d ", x);
	}

	return 0;
}