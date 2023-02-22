#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *parent=NULL, **child=NULL, *child_count=NULL, del, *queue=NULL, front=0, rear=0, count=0;

	scanf("%d", &N);
	parent=(int *)malloc(N*sizeof(int));
	child_count=(int *)calloc(N,sizeof(int));
	child=(int **)malloc(N*sizeof(int *));
	queue=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &parent[n]);
		if(parent[n]!=-1)
			child_count[parent[n]]++;
	}

	for(int n=0;n<N;n++)
		child[n]=(int *)malloc(child_count[n]*sizeof(int));

	free(child_count);
	child_count=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
		if(parent[n]!=-1)
			child[parent[n]][child_count[parent[n]]++]=n;

	scanf("%d", &del);
	if(parent[del]>=0)
		child_count[parent[del]]--;
	queue[rear++]=del;

	while(front<rear)
	{
		for(int i=0;i<child_count[queue[front]];i++)
			queue[rear++]=child[queue[front]][i];
		child_count[queue[front++]]=-1;
	}

	for(int n=0;n<N;n++)
		count+=child_count[n]==0;

	printf("%d\n", count);
	free(child_count);
	for(int n=0;n<N;n++)
		free(child[n]);
	free(queue);
	free(child);
	free(parent);
	return 0;
}