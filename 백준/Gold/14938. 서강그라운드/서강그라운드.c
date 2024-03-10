#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, m, r, *t=NULL, max=0, **distance=NULL, a, b, l;

	scanf("%d%d%d", &n, &m, &r);
	t=(int *)malloc((n+1)*sizeof(int));
	distance=(int **)malloc((n+1)*sizeof(int *));

	for(int i=1;i<=n;++i)
	{
		scanf("%d", &t[i]);
		distance[i]=(int *)malloc((n+1)*sizeof(int));
		for(int j=1;j<=n;++j)
			distance[i][j]=10000000;
		distance[i][i]=0;
	}

	while(r--)
	{
		scanf("%d%d%d", &a, &b, &l);
		distance[a][b]=distance[a][b]<l?distance[a][b]:l;
		distance[b][a]=distance[b][a]<l?distance[b][a]:l;
	}

	for(int mid=1;mid<=n;++mid)
		for(int start=1;start<=n;++start)
			for(int end=1;end<=n;++end)
				distance[start][end]=distance[start][mid]+distance[mid][end]<distance[start][end]?distance[start][mid]+distance[mid][end]:distance[start][end];

	for(int i=1;i<=n;++i)
	{
		int sum=0;

		for(int j=1;j<=n;++j)
			if(distance[i][j]<=m)
				sum+=t[j];

		max=max<sum?sum:max;
		free(distance[i]);
	}

	printf("%d", max);
	free(distance);
	free(t);
	return 0;
}