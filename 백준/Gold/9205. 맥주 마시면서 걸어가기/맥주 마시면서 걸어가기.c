#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int t, n, *y=NULL, *x=NULL, fes_y, fes_x, *queue=NULL, front, rear;
	bool *visited=NULL, arrived;

	scanf("%d", &t);
	for(int tc=0;tc<t;tc++)
	{
		scanf("%d", &n);
		y=(int *)malloc((n+1)*sizeof(int));
		x=(int *)malloc((n+1)*sizeof(int));
		queue=(int *)malloc(n*sizeof(int));
		visited=(bool *)calloc(n+1,sizeof(bool));
		front=rear=0;
		arrived=false;

		for(int i=0;i<=n;i++)
			scanf("%d%d", &y[i], &x[i]);
		scanf("%d%d", &fes_y, &fes_x);

		queue[rear++]=0;
		visited[0]=true;

		while(front<rear)
		{
			if(abs(y[queue[front]]-fes_y)+abs(x[queue[front]]-fes_x)<=1000)
			{
				arrived=true;
				break;
			}
			for(int i=1;i<=n;i++)
				if(!visited[i] && abs(y[i]-y[queue[front]])+abs(x[i]-x[queue[front]])<=1000)
				{
					visited[i]=true;
					queue[rear++]=i;
				}
			front++;
		}

		printf("%s\n", arrived?"happy":"sad");
		free(queue);
		free(visited);
		free(y);
		free(x);
	}

	return 0;
}