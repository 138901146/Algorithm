#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<memory.h>

#define MAX_N 100
#define MAX_V 202
#define S 200
#define E 201
#define INF 1000000000

int main(void)
{
	int N, M, capacity[MAX_V][MAX_V]={0}, C[MAX_V][MAX_V]={0}, flow[MAX_V][MAX_V]={0}, **adjacent_list=malloc(MAX_V*sizeof(int *)), adjacent_list_count[MAX_V]={0}, ans=0, previous[MAX_V], distance[MAX_V], queue[50000];

	scanf("%d%d", &N, &M);

	for(int i=MAX_N;i<MAX_N+N;++i)
	{
		scanf("%d", &capacity[i][E]);
		++adjacent_list_count[E];
		++adjacent_list_count[i];
	}

	for(int i=0;i<M;++i)
	{
		scanf("%d", &capacity[S][i]);
		++adjacent_list_count[S];
		++adjacent_list_count[i];
	}

	for(int i=0;i<M;++i)
		for(int j=MAX_N;j<MAX_N+N;++j)
		{
			scanf("%d", &C[i][j]);
			C[j][i]=-C[i][j];
			capacity[i][j]=INF;
			++adjacent_list_count[i];
			++adjacent_list_count[j];
		}

	for(int i=0;i<MAX_V;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	for(int i=MAX_N;i<MAX_N+N;++i)
	{
		adjacent_list[E][adjacent_list_count[E]++]=i;
		adjacent_list[i][adjacent_list_count[i]++]=E;
	}

	for(int i=0;i<M;++i)
	{
		adjacent_list[S][adjacent_list_count[S]++]=i;
		adjacent_list[i][adjacent_list_count[i]++]=S;
	}

	for(int i=0;i<M;++i)
		for(int j=MAX_N;j<MAX_N+N;j++)
		{
			adjacent_list[j][adjacent_list_count[j]++]=i;
			adjacent_list[i][adjacent_list_count[i]++]=j;
		}

	while(1)
	{
		int front=0, rear=1, min_flow=INF;
		bool inqueue[MAX_V]={0};

		memset(previous,-1,MAX_V*sizeof(int));
		for(int i=0;i<MAX_V;++i)
			distance[i]=INF;
		distance[S]=0;
		inqueue[S]=true;
		queue[0]=S;

		while(front<rear)
		{
			int current=queue[front++];

			inqueue[current]=false;

			for(int i=0;i<adjacent_list_count[current];++i)
			{
				int next=adjacent_list[current][i];

				if(flow[current][next]<capacity[current][next] && distance[current]+C[current][next]<distance[next])
				{
					distance[next]=distance[current]+C[current][next];
					previous[next]=current;
					if(!inqueue[next])
					{
						queue[rear++]=next;
						inqueue[next]=true;
					}
				}
			}
		}

		if(previous[E]==-1)
			break;

		for(int i=E;i!=S;i=previous[i])
			min_flow=min_flow<capacity[previous[i]][i]-flow[previous[i]][i]?min_flow:capacity[previous[i]][i]-flow[previous[i]][i];

		for(int i=E;i!=S;i=previous[i])
		{
			ans+=min_flow*C[previous[i]][i];
			flow[previous[i]][i]+=min_flow;
			flow[i][previous[i]]-=min_flow;
		}
	}

	printf("%d", ans);
	for(int i=0;i<MAX_V;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	return 0;
}