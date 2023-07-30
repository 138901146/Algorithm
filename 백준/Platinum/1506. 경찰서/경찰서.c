#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int N, **city=NULL, *city_count=NULL, *parent=NULL, *stack=NULL, top=0, **SCC=NULL, *SCC_count=NULL, id=1;
bool *found=NULL;

int DFS(int x)
{
	parent[x]=id++;
	stack[top++]=x;

	int p=parent[x];

	for(int i=0;i<city_count[x];i++)
	{
		int y=city[x][i];

		if(!parent[y])
		{
			int next=DFS(y);
			p=p<next?p:next;
		}
		else if(!found[y])
			p=p<parent[y]?p:parent[y];
	}

	if(p==parent[x])
	{
		int *scc=malloc(N*sizeof(int)), count=0;

		while(x)
		{
			int y=stack[--top];
			scc[count++]=y;
			found[y]=true;

			if(x==y)
				break;
		}

		SCC_count[scc[0]]=count;
		SCC[scc[0]]=(int *)malloc(count*sizeof(int));

		for(int i=0;i<count;i++)
			SCC[scc[0]][i]=scc[i];

		free(scc);
	}

	return p;
}

int main(void)
{
	int M, *cost=NULL, *connected=NULL, sum=0;

	scanf("%d", &N);
	connected=(int *)malloc((N+1)*sizeof(int));
	city_count=(int *)calloc(N+1,sizeof(int));
	city=(int **)malloc((N+1)*sizeof(int *));
	cost=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;n++)
		scanf("%d", &cost[n]);

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%1d", &connected[j]);
			city_count[i]+=connected[j];
		}

		city[i]=(int *)malloc(city_count[i]*sizeof(int));
		city_count[i]=0;

		for(int j=1;j<=N;j++)
			if(connected[j])
				city[i][city_count[i]++]=j;
	}
	free(connected);

	found=(bool *)calloc(N+1,sizeof(bool));
	parent=(int *)calloc(N+1,sizeof(int));
	SCC=(int **)malloc((N+1)*sizeof(int *));
	SCC_count=(int *)calloc(N+1,sizeof(int));
	stack=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;n++)
		if(!parent[n])
			DFS(n);

	for(int n=1;n<=N;n++)
	{
		if(SCC_count[n])
		{
			int max=1000000;
			for(int i=0;i<SCC_count[n];i++)
				max=cost[SCC[n][i]]<max?cost[SCC[n][i]]:max;
			sum+=max;
			free(SCC[n]);
		}
		free(city[n]);
	}
	printf("%d\n", sum);
	free(SCC);
	free(city);
	free(stack);
	free(parent);
	free(city_count);
	free(SCC_count);
	free(found);
	free(cost);
	return 0;
}