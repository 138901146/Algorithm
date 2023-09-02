#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	int who, what;
}
laptop;

int N, *owner=NULL, **assume=NULL, *assume_count=NULL;
laptop *claim=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<assume_count[current];++i)
		if(!visited[assume[current][i]])
		{
			visited[assume[current][i]]=true;

			if(owner[assume[current][i]]==0 || dfs(owner[assume[current][i]]))
			{
				owner[assume[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, count=0;

	scanf("%d%d", &N, &M);
	claim=(laptop *)malloc(M*sizeof(laptop));
	owner=(int *)calloc(N+1,sizeof(int));
	assume=(int **)malloc((N+1)*sizeof(int *));
	assume_count=(int *)calloc(N+1,sizeof(int));
	visited=(bool *)malloc((N+1)*sizeof(bool));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &claim[m].who, &claim[m].what);
		++assume_count[claim[m].who];
	}

	for(int n=1;n<=N;++n)
	{
		assume[n]=(int *)malloc(assume_count[n]*sizeof(int));
		assume_count[n]=0;
	}

	for(int m=0;m<M;++m)
		assume[claim[m].who][assume_count[claim[m].who]++]=claim[m].what;
	free(claim);

	for(int n=1;n<=N;++n )
	{
		for(int i=1;i<=N;++i)
			visited[i]=false;
		dfs(n);
	}

	while(N)
	{
		free(assume[N]);
		count+=owner[N--]>0;
	}

	printf("%d", count);
	free(assume);
	free(assume_count);
	free(visited);
	free(owner);
	return 0;
}