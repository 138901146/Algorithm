#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *S=NULL, **cow=NULL, *cow_count=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<cow_count[current];i++)
		if(!visited[cow[current][i]])
		{
			visited[cow[current][i]]=true;

			if(S[cow[current][i]]==0 || dfs(S[cow[current][i]]))
			{
				S[cow[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, count=0;

	scanf("%d%d", &N, &M);
	cow=(int **)malloc((N+1)*sizeof(int *));
	cow_count=(int *)malloc((N+1)*sizeof(int));
	S=(int *)calloc(M+1,sizeof(int));
	visited=(bool *)malloc((M+1)*sizeof(bool));

	for(int n=1;n<=N;n++)
	{
		scanf("%d", &cow_count[n]);
		cow[n]=(int *)malloc(cow_count[n]*sizeof(int));

		for(int i=0;i<cow_count[n];i++)
			scanf("%d", &cow[n][i]);
	}

	for(int n=1;n<=N;n++)
	{
		for(int m=1;m<=M;m++)
			visited[m]=false;
		dfs(n);
	}

	while(M)
		count+=S[M--]>0;

	printf("%d", count);
	while(N)
		free(cow[N--]);
	free(cow);
	free(cow_count);
	free(S);
	free(visited);
	return 0;
}