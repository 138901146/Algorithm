#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int N, **trip=NULL, *trip_count=NULL, *parent=NULL, *stack=NULL, top=0, **SCC=NULL, *SCC_count=NULL, id=1, num=0;
bool *found=NULL;

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int DFS(int x)
{
	parent[x]=id++;
	stack[top++]=x;

	int p=parent[x];

	for(int i=0;i<trip_count[x];i++)
	{
		int y=trip[x][i];

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
		num++;
		for(int i=0;i<count;i++)
			SCC[scc[0]][i]=scc[i];

		free(scc);
	}

	return p;
}

int main(void)
{
	int M, **flight=NULL, A, B;

	scanf("%d%d", &N, &M);
	flight=(int **)malloc(M*sizeof(int *));
	trip_count=(int *)calloc(N+1,sizeof(int));
	trip=(int **)malloc((N+1)*sizeof(int *));

	for(int m=0;m<M;m++)
	{
		flight[m]=(int *)malloc(2*sizeof(int));
		scanf("%d%d", &flight[m][0], &flight[m][1]);
		trip_count[flight[m][0]]++;
	}

	for(int n=1;n<=N;n++)
	{
		trip[n]=(int *)malloc(trip_count[n]*sizeof(int));
		trip_count[n]=0;
	}

	for(int m=0;m<M;m++)
	{
		trip[flight[m][0]][trip_count[flight[m][0]]++]=flight[m][1];
		free(flight[m]);
	}
	free(flight);

	found=(bool *)calloc(N+1,sizeof(bool));
	parent=(int *)calloc(N+1,sizeof(int));
	SCC=(int **)malloc((N+1)*sizeof(int *));
	SCC_count=(int *)calloc(N+1,sizeof(int));
	stack=(int *)malloc((N+1)*sizeof(int));
	for(int n=1;n<=N;n++)
		qsort((void *)trip[n],(size_t)trip_count[n],sizeof(int),compare);

	for(int n=1;n<=N&&num<2;n++)
		if(!parent[n])
			DFS(n);

	printf("%s\n", num<2?"Yes":"No");
	for(int n=1;n<=N;n++)
	{
		if(SCC_count[n])
			free(SCC[n]);
		free(trip[n]);
	}
	free(SCC);
	free(trip);
	free(stack);
	free(parent);
	free(trip_count);
	free(SCC_count);
	free(found);
	return 0;
}