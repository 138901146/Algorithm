#include<stdio.h>
#include<malloc.h>

int **enemy=NULL, *enemy_count=NULL, *team=NULL, flag=1;

void search_enemy(int current,int allocated)
{
	if(!flag)
		return;

	for(int i=0;i<enemy_count[current];++i)
	{
		int next=enemy[current][i];

		if(team[next]==team[current])
		{
			flag=0;
			return;
		}
		else if(!team[next])
		{
			team[next]=allocated^1;
			search_enemy(next,allocated^1);
		}
	}
}

int main(void)
{
	int N, M, **edge=NULL;

	scanf("%d%d", &N, &M);
	edge=(int **)malloc(M*sizeof(int *));
	enemy=(int **)malloc((N+1)*sizeof(int *));
	enemy_count=(int *)calloc(N+1,sizeof(int));

	for(int m=0;m<M;++m)
	{
		edge[m]=(int *)malloc(2*sizeof(int));

		for(int i=0;i<2;++i)
		{
			scanf("%d", &edge[m][i]);
			++enemy_count[edge[m][i]];
		}
	}

	for(int n=1;n<=N;++n)
	{
		enemy[n]=(int *)malloc(enemy_count[n]*sizeof(int));
		enemy_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		for(int i=0;i<2;++i)
			enemy[edge[m][i]][enemy_count[edge[m][i]]++]=edge[m][i^1];
		free(edge[m]);
	}
	free(edge);

	team=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N && flag;++n)
		if(!team[n])
		{
			team[n]=2;
			search_enemy(n,2);
		}

	printf("%d", flag);
	for(int n=1;n<=N;++n)
		free(enemy[n]);
	free(enemy);
	free(enemy_count);
	free(team);
	return 0;
}