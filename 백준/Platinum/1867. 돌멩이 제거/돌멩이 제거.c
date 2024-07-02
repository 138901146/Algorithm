#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	int r, c;
}
grid;

bool *visited=NULL;
int **adjacent_list=NULL, *size=NULL, *occupied=NULL;

bool dfs(int current)
{
	for(int i=0;i<size[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int n, k, count=0;
	grid *stone=NULL;

	scanf("%d%d", &n, &k);
	adjacent_list=(int **)malloc((n+1)*sizeof(int *));
	size=(int *)calloc(n+1,sizeof(int));
	stone=(grid *)malloc(k*sizeof(grid));

	for(int i=0;i<k;++i)
	{
		scanf("%d%d", &stone[i].r, &stone[i].c);
		++size[stone[i].r];
	}

	for(int i=1;i<=n;++i)
	{
		adjacent_list[i]=(int *)malloc(size[i]*sizeof(int));
		size[i]=0;
	}

	while(k--)
		adjacent_list[stone[k].r][size[stone[k].r]++]=stone[k].c;

	free(stone);
	occupied=(int *)calloc(n+1,sizeof(int));
	visited=(bool *)malloc((n+1)*sizeof(bool));

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			visited[j]=false;

		count+=dfs(i);
	}

	printf("%d", count);

	while(n)
		free(adjacent_list[n--]);
	free(adjacent_list);
	free(size);
	free(occupied);
	free(visited);
	return 0;
}