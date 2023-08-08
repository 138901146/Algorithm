#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int F, S, G, U, D, *queue=NULL, front=0, rear=0, count=0, *button=NULL;
	bool *visited=NULL;

	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	visited=(bool *)calloc(F+1,sizeof(bool));
	queue=(int *)malloc((F+1)*sizeof(int));
	button=(int *)malloc((F+1)*sizeof(int));

	queue[rear++]=S;
	visited[S]=true;

	while(front<rear && !visited[G])
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			if(queue[front]-D>0 && !visited[queue[front]-D])
			{
				visited[queue[front]-D]=true;
				button[queue[front]-D]=count+1;
				queue[rear++]=queue[front]-D;
			}
			if(queue[front]+U<=F && !visited[queue[front]+U])
			{
				visited[queue[front]+U]=true;
				button[queue[front]+U]=count+1;
				queue[rear++]=queue[front]+U;
			}

			front++;
		}
		count++;
	}

	if(visited[G])
		printf("%d\n", button[G]);
	else
		printf("use the stairs\n");
	free(button);
	free(visited);
	free(queue);
	return 0;
}