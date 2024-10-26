#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

typedef struct
{
	int A, B;
}
interest;

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
	int N, M, count=0;
	interest *list=NULL;

	scanf("%d%d", &N, &M);
	adjacent_list=(int **)malloc(N*sizeof(int *));
	adjacent_list_count=(int *)calloc(N,sizeof(int));
	occupied=(int *)malloc(N*sizeof(int));
	list=(interest *)malloc(M*sizeof(interest));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &list[m].A, &list[m].B);
		++adjacent_list_count[list[m].A];
	}

	for(int n=0;n<N;++n)
	{
		adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
		adjacent_list_count[n]=0;
		occupied[n]=-1;
	}

	while(M--)
		adjacent_list[list[M].A][adjacent_list_count[list[M].A]++]=list[M].B;
	free(list);

	visited=(bool *)malloc(N*sizeof(bool));

	for(int n=0;n<N;++n)
	{
		memset(visited,0,N);
		count+=dfs(n);
	}

	printf("%s", N==count?"YES":"NO");
	while(N--)
		free(adjacent_list[N]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(occupied);
	free(visited);
	return 0;
}