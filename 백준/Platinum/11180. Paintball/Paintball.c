#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct
{
	int A, B;
}
visible;

int *shot=NULL, **player=NULL, *player_count=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<player_count[current];++i)
		if(!visited[player[current][i]])
		{
			visited[player[current][i]]=true;

			if(shot[player[current][i]]==0 || dfs(shot[player[current][i]]))
			{
				shot[player[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, count=0;
	visible *relation=NULL;

	scanf("%d%d", &N, &M);
	player=(int **)malloc((N+1)*sizeof(int *));
	player_count=(int *)calloc(N+1,sizeof(int));
	relation=(visible *)malloc(M*sizeof(visible));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &relation[m].A, &relation[m].B);
		++player_count[relation[m].A];
		++player_count[relation[m].B];
	}

	for(int n=1;n<=N;++n)
	{
		player[n]=(int *)malloc(player_count[n]*sizeof(int));
		player_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		player[relation[m].A][player_count[relation[m].A]++]=relation[m].B;
		player[relation[m].B][player_count[relation[m].B]++]=relation[m].A;
	}
	free(relation);

	shot=(int *)calloc(N+1,sizeof(int));
	visited=(bool *)calloc(N+1,sizeof(bool));

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			visited[j]=false;
		count+=dfs(i);
	}

	if(count==N)
		for(int n=1;n<=N;++n)
			printf("%d\n", shot[n]);
	else
		printf("Impossible");

	for(int n=1;n<=N;++n)
		if(player_count[n])
			free(player[n]);
	free(player);
	free(player_count);
	free(shot);
	free(visited);
	return 0;
}