#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *A=NULL, *B=NULL, **adjacent_list=NULL, *adjacent_list_count=NULL, *min=NULL, *queue=NULL, front=0, rear=1, id, distance=0, count;

	scanf("%d%d", &N, &M);
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	A=(int *)malloc(M*sizeof(int));
	B=(int *)malloc(M*sizeof(int));
	min=(int *)malloc((N+1)*sizeof(int));

	for(int i=0;i<M;++i)
	{
		scanf("%d%d", &A[i], &B[i]);
		++adjacent_list_count[A[i]];
		++adjacent_list_count[B[i]];
	}

	for(int i=1;i<=N;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
		min[i]=99999;
	}

	for(int i=0;i<M;++i)
	{
		adjacent_list[A[i]][adjacent_list_count[A[i]]++]=B[i];
		adjacent_list[B[i]][adjacent_list_count[B[i]]++]=A[i];
	}
	free(A);
	free(B);

	queue=(int *)malloc(1000000*sizeof(int));
	queue[0]=1;
	min[1]=0;

	while(front<rear)
	{
		int current=queue[front++];

		for(int i=0;i<adjacent_list_count[current];++i)
		{
			int next=adjacent_list[current][i];

			if(min[current]+1<min[next])
			{
				min[next]=min[current]+1;
				queue[rear++]=next;
			}
		}
	}

	for(int i=2;i<=N;++i)
		if(distance<min[i])
		{
			id=i;
			distance=min[i];
			count=1;
		}
		else if(distance==min[i])
			++count;

	printf("%d %d %d", id, distance, count);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(queue);
	free(min);
	return 0;
}