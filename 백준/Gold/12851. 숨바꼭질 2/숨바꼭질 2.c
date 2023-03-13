#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, count=0, *queue=malloc(10000001*sizeof(int)), front=0, rear=0, *method=calloc(100002,sizeof(int)), *previous=calloc(100002,sizeof(int));

	scanf("%d%d", &N, &K);

	queue[rear++]=N;
	method[N]=1;

	if(N!=K)
		while(front<rear)
		{
			int previous_rear=rear, previous_front=front;

			while(front<previous_rear)
			{
				if(queue[front]>0 && previous[queue[front]-1]==0)
				{
					method[queue[front]-1]++;
					queue[rear++]=queue[front]-1;
				}
				if(queue[front]<100000 && previous[queue[front]+1]==0)
				{
					method[queue[front]+1]++;
					queue[rear++]=queue[front]+1;
				}
				if(queue[front]*2<100001 && previous[queue[front]*2]==0)
				{
					method[queue[front]*2]++;
					queue[rear++]=queue[front]*2;
				}
				front++;
			}

			count++;
			if(method[K]>0)
				break;
			for(int i=previous_front;i<rear;i++)
				previous[queue[i]]=method[queue[i]];
		}

	printf("%d\n%d\n", count, method[K]);
	free(method);
	free(queue);
	free(previous);
	return 0;
}