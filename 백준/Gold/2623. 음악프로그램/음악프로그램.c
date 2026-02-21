#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, M, **list=NULL, *parent=NULL, *child_count=NULL, **child=NULL, temp, *queue=NULL, front=0, rear=0;
	bool *visited=NULL;

	scanf("%d%d", &N, &M);
	parent=(int *)calloc(N+1,sizeof(int));
	visited=(bool *)calloc(N+1,sizeof(bool));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	list=(int **)malloc(M*sizeof(int *));
	queue=(int *)malloc(N*sizeof(int));

	for(int m=0;m<M;++m)
	{
		scanf("%d", &temp);
		list[m]=(int *)malloc((temp+1)*sizeof(int));
		list[m][0]=temp;
		for(int i=1;i<=list[m][0];++i)
			scanf("%d", &list[m][i]);

		for(int i=2;i<=list[m][0];++i)
		{
			++parent[list[m][i]];
			++child_count[list[m][i-1]];
		}
	}

	for(int n=1;n<=N;++n)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int m=0;m<M;++m)
		for(int i=1;i<list[m][0];++i)
			child[list[m][i]][child_count[list[m][i]]++]=list[m][i+1];

	for(int n=1;n<=N;++n)
		if(parent[n]==0)
		{
			queue[rear++]=n;
			visited[n]=true;
		}

	while(front<rear)
	{
		for(int i=0;i<child_count[queue[front]];++i)
			if(!--parent[child[queue[front]][i]]&&!visited[child[queue[front]][i]])
			{
				visited[child[queue[front]][i]]=true;
				queue[rear++]=child[queue[front]][i];
			}
		++front;
	}

	if(rear!=N)
		printf("0");
	else
		for(int n=0;n<N;++n)
			printf("%d\n", queue[n]);

	while(M)
		free(list[--M]);
	while(N)
		free(child[N--]);
	free(list);
	free(child);
	free(child_count);
	free(parent);
	free(queue);
	free(visited);
	return 0;
}