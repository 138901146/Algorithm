#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *vertex=NULL, *pq=NULL, size=1;

void add(int value)
{
	pq[size++]=value;
	int index=size-1;

	while(index>1)
		if(vertex[pq[index]]<=vertex[pq[index>>1]])
		{
			int temp=pq[index];
			pq[index]=pq[index>>1];
			pq[index>>1]=temp;
			index>>=1;
		}
		else
			break;
}

int get()
{
	bool set=false;
	int value=pq[1], index=1;
	pq[1]=pq[--size];

	while(index<size &&!set)
	{
		if(index*2+1<size)
		{
			if(vertex[pq[index*2+1]]<vertex[pq[index*2]])
			{
				if(vertex[pq[index]]>=vertex[pq[index*2+1]])
				{
					int temp=pq[index];
					pq[index]=pq[index*2+1];
					pq[index*2+1]=temp;
					index=(index<<1)+1;
				}
				else
					set=true;
			}
			else
			{
				if(vertex[pq[index]]>=vertex[pq[index*2]])
				{
					int temp=pq[index];
					pq[index]=pq[index*2];
					pq[index*2]=temp;
					index<<=1;
				}
				else
					set=true;
			}
		}
		else if(index*2+1==size)
		{
				if(vertex[pq[index]]>=vertex[pq[index*2]])
				{
					int temp=pq[index];
					pq[index]=pq[index*2];
					pq[index*2]=temp;
					index<<=1;
				}
				else
					set=true;
		}
		else
			set=true;
	}

	return value;
}

int main(void)
{
	int V, E, **edge=NULL, K, *edge_count=NULL, ***local_edge=NULL;

	scanf("%d%d", &V, &E);
	scanf("%d", &K);
	vertex=(int *)malloc((V+1)*sizeof(int));
	edge_count=(int *)calloc(V+1,sizeof(int));
	edge=(int **)malloc(E*sizeof(int *));
	local_edge=(int ***)malloc((V+1)*sizeof(int **));
	pq=(int *)malloc(1000*(V+1)*sizeof(int));
	for(int v=1;v<=V;v++)
		vertex[v]=1<<29;
	for(int e=0;e<E;e++)
	{
		edge[e]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<3;i++)
			scanf("%d", &edge[e][i]);
		edge_count[edge[e][0]]++;
	}

	for(int v=1;v<=V;v++)
	{
		local_edge[v]=(int **)malloc(edge_count[v]*sizeof(int *));
		for(int i=0;i<edge_count[v];i++)
			local_edge[v][i]=(int *)malloc(2*sizeof(int));
		edge_count[v]=0;
	}

	for(int e=0;e<E;e++)
	{
		local_edge[edge[e][0]][edge_count[edge[e][0]]][0]=edge[e][1];
		local_edge[edge[e][0]][edge_count[edge[e][0]]++][1]=edge[e][2];
		free(edge[e]);
	}
	free(edge);

	vertex[K]=0;
	for(int i=0;i<edge_count[K];i++)
		if(local_edge[K][i][1]<vertex[local_edge[K][i][0]])
			vertex[local_edge[K][i][0]]=local_edge[K][i][1];

	for(int v=1;v<=V;v++)
		add(v);

	while(size>1)
	{
		int target=get();

		for(int i=0;i<edge_count[target];i++)
			if(vertex[local_edge[target][i][0]]>vertex[target]+local_edge[target][i][1])
			{
				vertex[local_edge[target][i][0]]=vertex[target]+local_edge[target][i][1];
				add(local_edge[target][i][0]);
			}
	}

	for(int v=1;v<=V;v++)
	{
		if(vertex[v]==1<<29)
			printf("INF\n");
		else
			printf("%d\n", vertex[v]);
		for(int i=0;i<edge_count[v];i++)
			free(local_edge[v][i]);
		free(local_edge[v]);
	}
	free(local_edge);
	free(edge_count);
	free(vertex);
	free(pq);
	return 0;
}