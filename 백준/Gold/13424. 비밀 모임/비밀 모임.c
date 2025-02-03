#include<stdio.h>

#define INF 123456789

int main(void)
{
	int T, N, M, a, b, c, K, room[100], distance[101][101], min, min_id;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &M);

		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<i;++j)
				distance[i][j]=distance[j][i]=INF;
			distance[i][i]=0;
		}

		while(M--)
		{
			scanf("%d%d%d", &a, &b, &c);
			distance[a][b]=distance[b][a]=c;
		}

		scanf("%d", &K);
		for(int k=0;k<K;++k)
			scanf("%d", &room[k]);

		for(int mid=1;mid<=N;++mid)
			for(int start=1;start<=N;++start)
				for(int end=1;end<=N;++end)
					if(distance[start][mid]+distance[mid][end]<distance[start][end])
						distance[start][end]=distance[start][mid]+distance[mid][end];

		min=INF;
		for(int n=1;n<=N;++n)
		{
			int sum=0;

			for(int k=0;k<K;++k)
				sum+=distance[n][room[k]];

			if(sum<min)
			{
				min=sum;
				min_id=n;
			}
		}

		printf("%d\n", min_id);
	}

	return 0;
}