#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, *primitive_count=NULL, **definitive=NULL, *definitive_count=NULL, *subject=NULL, *queue=NULL, front=0, rear=0, **order=NULL, count=1;

	scanf("%d%d", &N, &M);
	subject=(int *)malloc((N+1)*sizeof(int));
	queue=(int *)malloc(N*sizeof(int));
	order=(int **)malloc(M*sizeof(int *));
	primitive_count=(int *)calloc(N+1,sizeof(int));
	definitive_count=(int *)calloc(N+1,sizeof(int));
	definitive=(int **)malloc((N+1)*sizeof(int *));

	for(int m=0;m<M;m++)
	{
		order[m]=(int *)malloc(2*sizeof(int));
		scanf("%d%d", &order[m][0], &order[m][1]);
		primitive_count[order[m][1]]++;
		definitive_count[order[m][0]]++;
	}

	for(int n=1;n<=N;n++)
	{
		definitive[n]=(int *)malloc(definitive_count[n]*sizeof(int));
		definitive_count[n]=0;
		if(primitive_count[n]==0)
			queue[rear++]=n;
	}

	for(int m=0;m<M;m++)
	{
		definitive[order[m][0]][definitive_count[order[m][0]]++]=order[m][1];
		free(order[m]);
	}
	free(order);

	while(front<rear)
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			subject[queue[front]]=count;
			for(int i=0;i<definitive_count[queue[front]];i++)
			{
				primitive_count[definitive[queue[front]][i]]--;
				if(primitive_count[definitive[queue[front]][i]]==0)
					queue[rear++]=definitive[queue[front]][i];
			}

			front++;
		}

		count++;
	}

	for(int n=1;n<=N;n++)
	{
		printf("%d ", subject[n]);
		free(definitive[n]);
	}
	free(definitive);
	free(definitive_count);
	free(primitive_count);
	free(subject);
	free(queue);
	return 0;
}