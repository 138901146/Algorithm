#include<stdio.h>

int main(void)
{
	int n, m, distance[101][101], p1, p2, x, y;

	scanf("%d", &n);

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			distance[i][j]=127;
		distance[i][i]=0;
	}

	scanf("%d%d", &p1, &p2);
	scanf("%d", &m);

	while(m--)
	{
		scanf("%d%d", &x, &y);
		distance[x][y]=distance[y][x]=1;
	}

	for(int mid=1;mid<=n;++mid)
		for(int start=1;start<=n;++start)
			for(int end=1;end<=n;++end)
				if(distance[start][mid]+distance[mid][end]<distance[start][end])
					distance[start][end]=distance[end][start]=distance[start][mid]+distance[mid][end];

	printf("%d", distance[p1][p2]==127?-1:distance[p1][p2]);
	return 0;
}