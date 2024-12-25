#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

#define INF 99999

int **adjacent_list=NULL, *adjacent_list_count=NULL, occupied[20000], level[10000];
bool used[10000];

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(occupied[next]==-1 || level[occupied[next]]==level[current]+1&&dfs(occupied[next]))
		{
			used[current]=true;
			occupied[next]=current;
			return true;
		}
	}

	return false;
}

int main(void)
{
	int n, queue[10000], front, rear, flow;

	while(scanf("%d", &n)!=EOF)
	{
		int matched=0;

		adjacent_list=(int **)malloc(n*sizeof(int *));
		adjacent_list_count=(int *)calloc(n,sizeof(int));
		memset(occupied,-1,20000*sizeof(int));
		memset(used,0,10000);

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

		do
		{
			flow=front=rear=0;

			for(int i=0;i<n;++i)
				if(used[i])
					level[i]=INF;
				else
				{
					level[i]=0;
					queue[rear++]=i;
				}

			while(front<rear)
			{
				int current=queue[front++];

				for(int i=0;i<adjacent_list_count[current];++i)
				{
					int next=adjacent_list[current][i];

					if(occupied[next]!=-1 && level[occupied[next]]==INF)
					{
						level[occupied[next]]=level[current]+1;
						queue[rear++]=occupied[next];
					}
				}
			}

			for(int i=0;i<n;++i)
				flow+=!used[i]&&dfs(i);

			matched+=flow;
		}
		while(flow);

		printf("%d\n", matched);
		for(int i=0;i<n;++i)
			free(adjacent_list[i]);
		free(adjacent_list);
		free(adjacent_list_count);
	}

	return 0;
}