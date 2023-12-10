#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *eaten=NULL, **chain=NULL, *chain_count=NULL;
bool *visited=NULL;

typedef struct
{
	int size, speed, intelligence;
}
shark_info;

bool dfs(int current)
{
	for(int i=0;i<chain_count[current];++i)
		if(!visited[chain[current][i]])
		{
			visited[chain[current][i]]=true;

			if(eaten[chain[current][i]]==0 || dfs(eaten[chain[current][i]]))
			{
				eaten[chain[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, count=0;
	shark_info *shark=NULL;

	scanf("%d", &N);
	shark=(shark_info *)malloc((N+1)*sizeof(shark_info));
	chain=(int **)malloc((N+1)*sizeof(int *));
	chain_count=(int *)calloc(N+1,sizeof(int));
	eaten=(int *)calloc(N+1,sizeof(int));
	visited=(bool *)malloc((N+1)*sizeof(bool));

	for(int n=1;n<=N;++n)
		scanf("%d%d%d", &shark[n].size, &shark[n].speed, &shark[n].intelligence);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j)
			{
				if(shark[i].size==shark[j].size && shark[i].speed==shark[j].speed && shark[i].intelligence==shark[j].intelligence)
						chain_count[i]+=i>j;
				else if(shark[i].size>=shark[j].size && shark[i].speed>=shark[j].speed && shark[i].intelligence>=shark[j].intelligence)
					++chain_count[i];
			}

	for(int n=1;n<=N;++n)
	{
		chain[n]=(int *)malloc(chain_count[n]*sizeof(int));
		chain_count[n]=0;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j)
			{
				if(shark[i].size==shark[j].size && shark[i].speed==shark[j].speed && shark[i].intelligence==shark[j].intelligence)
				{
					if(i>j)
						chain[i][chain_count[i]++]=j;
				}
				else if(shark[i].size>=shark[j].size && shark[i].speed>=shark[j].speed && shark[i].intelligence>=shark[j].intelligence)
					chain[i][chain_count[i]++]=j;
			}
	free(shark);

	for(int n=1;n<=N;++n)
		for(int i=0;i<2;++i)
		{
			for(int j=1;j<=N;++j)
				visited[j]=false;
			dfs(n);
		}

	for(int n=1;n<=N;++n)
	{
		count+=eaten[n]==0;
		free(chain[n]);
	}

	printf("%d", count);
	free(chain);
	free(chain_count);
	free(eaten);
	free(visited);
	return 0;
}