#include<stdio.h>

#define INF 12345678

typedef struct
{
	int cost, last;
}
path;

int main(void)
{
	int n, m, a, b, c;
	path road[101][101];

	scanf("%d", &n);
	scanf("%d", &m);

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
			road[i][j].cost=road[j][i].cost=INF;
		road[i][i].cost=0;
		road[i][i].last=i;
	}

	while(m--)
	{
		scanf("%d%d%d", &a, &b, &c);

		if(c<road[a][b].cost)
		{
			road[a][b].cost=c;
			road[a][b].last=a;
		}
	}

	for(int mid=1;mid<=n;++mid)
		for(int start=1;start<=n;++start)
			for(int end=1;end<=n;++end)
				if(road[start][mid].cost+road[mid][end].cost<road[start][end].cost)
				{
					road[start][end].cost=road[start][mid].cost+road[mid][end].cost;
					road[start][end].last=road[mid][end].last;
				}

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ", road[i][j].cost==INF?0:road[i][j].cost);
		printf("\n");
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==j || road[i][j].cost==INF)
			{
				printf("0\n");
				continue;
			}

			int count=0, backtrace[100]={j,0,};

			while(backtrace[count]!=i)
			{
				backtrace[count+1]=road[i][backtrace[count]].last;
				++count;
			}

			printf("%d", count+1);
			while(count)
				printf(" %d", backtrace[count--]);
			printf(" %d\n", j);
		}

	return 0;
}