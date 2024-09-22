#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

int **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int n;

	while(scanf("%d", &n)!=EOF)
	{
		int count=0;

		adjacent_list=(int **)malloc(n*sizeof(int *));
		adjacent_list_count=(int *)calloc(n,sizeof(int));

		for(int i=0;i<n;++i)
		{
			int id;

			scanf("%d", &id);
			while(getchar()!=':');
			while(getchar()!='(');
			scanf("%d", &adjacent_list_count[id]);
			while(getchar()!=')');

			adjacent_list[id]=(int *)malloc(adjacent_list_count[id]*sizeof(int));
			for(int j=0;j<adjacent_list_count[id];++j)
				scanf("%d", &adjacent_list[id][j]);
		}

		occupied=(int *)malloc((n<<1)*sizeof(int));
		visited=(bool *)malloc((n<<1)*sizeof(bool));

		for(int i=0;i<(n<<1);++i)
			occupied[i]=-1;

		for(int i=0;i<n;++i)
		{
			memset(visited,0,n<<1);
			count+=dfs(i);
		}

		printf("%d\n", count);
		for(int i=0;i<n;++i)
			free(adjacent_list[i]);
		free(adjacent_list);
		free(adjacent_list_count);
		free(occupied);
		free(visited);
	}

	return 0;
}