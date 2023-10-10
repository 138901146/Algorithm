#include<stdio.h>

int main(void)
{
	int n, m, a, b, c, distance[101][101];

	scanf("%d", &n);
	scanf("%d", &m);

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			distance[i][j]=100000000;
		distance[i][i]=0;
	}

	while(m--)
	{
		scanf("%d%d%d", &a, &b, &c);
		distance[a][b]=distance[a][b]<c?distance[a][b]:c;
	}

	for(int mid=1;mid<=n;++mid)
		for(int start=1;start<=n;++start)
			for(int end=1;end<=n;++end)
				distance[start][end]=distance[start][end]<distance[start][mid]+distance[mid][end]?distance[start][end]:distance[start][mid]+distance[mid][end];

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ", distance[i][j]==100000000?0:distance[i][j]);
		printf("\n");
	}
	return 0;
}