#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

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
	int N, M, A, B, *relation=NULL, count=0;

	scanf("%d%d", &N, &M);
	player=(int **)malloc((N+1)*sizeof(int *));
	player_count=(int *)calloc(N+1,sizeof(int));
	relation=(int *)malloc(M*sizeof(int));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &A, &B);
		++player_count[A];
		++player_count[B];
		relation[m]=A<<10|B;
	}

	for(int n=1;n<=N;++n)
	{
		player[n]=(int *)malloc(player_count[n]*sizeof(int));
		player_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		A=relation[m]>>10;
		B=relation[m]&1023;
		player[A][player_count[A]++]=B;
		player[B][player_count[B]++]=A;
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