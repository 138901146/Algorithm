#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *occupied=NULL, **pilot=NULL, *pilot_count=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<pilot_count[current];++i)
		if(!visited[pilot[current][i]])
		{
			visited[pilot[current][i]]=true;

			if(occupied[pilot[current][i]]==0 || dfs(occupied[pilot[current][i]]))
			{
				occupied[pilot[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int K, n, m, x=0;

	scanf("%d", &K);

	while(K--)
	{
		int count=0;

		scanf("%d%d", &m, &n);
		pilot=(int **)malloc((n+1)*sizeof(int *));
		pilot_count=(int *)malloc((n+1)*sizeof(int));
		occupied=(int *)calloc(m+1,sizeof(int));
		visited=(bool *)malloc((m+1)*sizeof(bool));

		for(int i=1;i<=n;++i)
		{
			scanf("%d", &pilot_count[i]);
			pilot[i]=(int *)malloc(pilot_count[i]*sizeof(int));

			for(int j=0;j<pilot_count[i];++j)
				scanf("%d", &pilot[i][j]);
		}

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				visited[j]=false;
			count+=dfs(i);
		}

		printf("Data Set %d:\n%d\n\n", ++x, count);
		while(n)
			free(pilot[n--]);
		free(pilot);
		free(pilot_count);
		free(occupied);
		free(visited);
	}

	return 0;
}