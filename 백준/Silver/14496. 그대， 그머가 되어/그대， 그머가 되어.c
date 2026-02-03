#include<stdio.h>
#include<malloc.h>

#define INF 65535

int main(void)
{
	int N, M, a, b, **adjacent_list=NULL, *adjacent_list_count=NULL, *x=NULL, *y=NULL, *queue=NULL, front=0, rear=1, *min=NULL;

	scanf("%d%d", &a, &b);
	scanf("%d%d", &N, &M);

	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	x=(int *)malloc(M*sizeof(int));
	y=(int *)malloc(M*sizeof(int));

	for(int i=0;i<M;++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		++adjacent_list_count[x[i]];
		++adjacent_list_count[y[i]];
	}

	for(int i=1;i<=N;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	for(int i=0;i<M;++i)
	{
		adjacent_list[x[i]][adjacent_list_count[x[i]]++]=y[i];
		adjacent_list[y[i]][adjacent_list_count[y[i]]++]=x[i];
	}

	free(x);
	free(y);
	min=(int *)malloc((N+1)*sizeof(int));
	queue=(int *)malloc(N*sizeof(int));

	for(int i=1;i<=N;++i)
		min[i]=INF;
	min[a]=0;
	queue[0]=a;

	while(front<rear&&min[b]==INF)
	{
		for(int i=0;i<adjacent_list_count[queue[front]];++i)
			if(min[queue[front]]+1<min[adjacent_list[queue[front]][i]])
			{
				min[adjacent_list[queue[front]][i]]=min[queue[front]]+1;
				queue[rear++]=adjacent_list[queue[front]][i];
			}

		++front;
	}

	printf("%d", min[b]==INF?-1:min[b]);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(min);
	free(queue);
	return 0;
}