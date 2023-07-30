#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int V, **vertex=NULL, *vertex_count=NULL, *parent=NULL, *stack=NULL, top=0, **SCC=NULL, *SCC_count=NULL, id=1, num=0;
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

	for(int i=0;i<vertex_count[x];i++)
	{
		int y=vertex[x][i];

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
		int *scc=malloc(V*sizeof(int)), count=0;

		while(x)
		{
			int y=stack[--top];
			scc[count++]=y;
			found[y]=true;

			if(x==y)
				break;
		}

		qsort((void *)scc,(size_t)count,sizeof(int),compare);
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
	int E, *edge=NULL, A, B;

	scanf("%d%d", &V, &E);
	edge=(int *)malloc(E*sizeof(int));
	vertex_count=(int *)calloc(V+1,sizeof(int));
	vertex=(int **)malloc((V+1)*sizeof(int *));

	for(int e=0;e<E;e++)
	{
		scanf("%d%d", &A, &B);
		edge[e]=A<<14|B;
		vertex_count[A]++;
	}

	for(int v=1;v<=V;v++)
	{
		vertex[v]=(int *)malloc(vertex_count[v]*sizeof(int));
		vertex_count[v]=0;
	}

	for(int e=0;e<E;e++)
	{
		A=edge[e]>>14;
		B=edge[e]&16383;
		vertex[A][vertex_count[A]++]=B;
	}
	free(edge);

	found=(bool *)calloc(V+1,sizeof(bool));
	parent=(int *)calloc(V+1,sizeof(int));
	SCC=(int **)malloc((V+1)*sizeof(int *));
	SCC_count=(int *)calloc(V+1,sizeof(int));
	stack=(int *)malloc((V+1)*sizeof(int));
	for(int v=1;v<=V;v++)
		qsort((void *)vertex[v],(size_t)vertex_count[v],sizeof(int),compare);

	for(int v=1;v<=V;v++)
		if(!parent[v])
			DFS(v);

	printf("%d\n", num);
	for(int v=1;v<=V;v++)
	{
		if(SCC_count[v])
		{
			for(int i=0;i<SCC_count[v];i++)
				printf("%d ", SCC[v][i]);
			printf("-1\n");
			free(SCC[v]);
		}
		free(vertex[v]);
	}
	free(SCC);
	free(vertex);
	free(stack);
	free(parent);
	free(vertex_count);
	free(SCC_count);
	free(found);
	return 0;
}