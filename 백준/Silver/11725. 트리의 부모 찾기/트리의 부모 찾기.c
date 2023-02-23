#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, **connected=NULL, *connected_count=NULL, **tree=NULL, *queue=NULL, *parent=NULL, front=0, rear=0;

	scanf("%d", &N);
	connected=(int **)malloc((N-1)*sizeof(int *));
	for(int n=0;n<N-1;n++)
		connected[n]=(int *)malloc(2*sizeof(int));
	connected_count=(int *)calloc(N+1,sizeof(int));
	parent=(int *)calloc(N+1,sizeof(int));
	tree=(int **)malloc((N+1)*sizeof(int *));
	queue=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N-1;i++)
	{
		scanf("%d%d", &connected[i][0], &connected[i][1]);
		if(connected[i][0]==1)
		{
			parent[connected[i][1]]=1;
			queue[rear++]=connected[i][1];
		}
		else if(connected[i][1]==1)
		{
			parent[connected[i][0]]=1;
			queue[rear++]=connected[i][0];
		}
		else
		{
			connected_count[connected[i][0]]++;
			connected_count[connected[i][1]]++;
		}
	}

	for(int i=1;i<=N;i++)
		tree[i]=(int *)calloc(connected_count[i],sizeof(int));

	for(int i=0;i<=N;i++)
		connected_count[i]=0;

	for(int i=0;i<N-1;i++)
	{
		if(connected[i][0]!=1 && connected[i][1]!=1)
		{
			tree[connected[i][0]][connected_count[connected[i][0]]++]=connected[i][1];
			tree[connected[i][1]][connected_count[connected[i][1]]++]=connected[i][0];
		}
	}

	while(front<rear)
	{
		for(int i=0;i<connected_count[queue[front]];i++)
			if(parent[tree[queue[front]][i]]==0)
			{
				parent[tree[queue[front]][i]]=queue[front];
				queue[rear++]=tree[queue[front]][i];
			}
		front++;
	}

	for(int i=2;i<=N;i++)
		printf("%d\n", parent[i]);
	for(int i=1;i<=N;i++)
		free(tree[i]);
	free(tree);
	free(queue);
	free(parent);
	free(connected_count);
	for(int n=0;n<N-1;n++)
		free(connected[n]);
	free(connected);
	return 0;
}