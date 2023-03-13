#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, **list=NULL, *parent=NULL, *child_count=NULL, **child=NULL, *queue=NULL, front=0, rear=0;
	bool *checked=NULL;

	scanf("%d%d", &N, &M);
	parent=(int *)calloc(N+1,sizeof(int));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	list=(int **)malloc(M*sizeof(int *));
	queue=(int *)malloc(N*sizeof(int));
	checked=(bool *)calloc(N+1,sizeof(bool));

	for(int m=0;m<M;m++)
	{
		list[m]=(int *)malloc(2*sizeof(int));
		scanf("%d%d", &list[m][0], &list[m][1]);
		parent[list[m][1]]++;
		child_count[list[m][0]]++;
	}

	for(int n=1;n<=N;n++)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int m=0;m<M;m++)
		child[list[m][0]][child_count[list[m][0]]++]=list[m][1];

	for(int n=1;n<=N;n++)
		if(parent[n]==0)
		{
			queue[rear++]=n;
			checked[n]=true;
		}

	while(front<rear)
	{
		for(int i=0;i<child_count[queue[front]];i++)
			if(--parent[child[queue[front]][i]]==0 && !checked[child[queue[front]][i]])
			{
				checked[child[queue[front]][i]]=true;
				queue[rear++]=child[queue[front]][i];
			}
		front++;
	}

	for(int i=0;i<rear;i++)
		printf("%d ", queue[i]);
	if(rear!=N)
		for(int i=1;i<=N;i++)
			if(!checked[i])
				printf("%d ", i);

	for(int m=0;m<M;m++)
		free(list[m]);
	for(int n=1;n<=N;n++)
		free(child[n]);
	free(list);
	free(child);
	free(child_count);
	free(parent);
	free(queue);
	free(checked);
	return 0;
}