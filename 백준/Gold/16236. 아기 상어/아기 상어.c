#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int fish[7]={0, }, N, **space=NULL, x, y, sec=0, total, size=2, eaten=0;

	scanf("%d", &N);
	space=(int **)malloc(N*sizeof(int *));
	for(int i=0;i<N;i++)
	{
		space[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;j++)
		{
			scanf("%d", &space[i][j]);
			if(space[i][j]==9)
			{
				y=i;
				x=j;
				space[i][j]=0;
			}
			else if(space[i][j]>0)
				fish[space[i][j]]++;
		}
	}

	total=fish[1];

	while(total>0)
	{
		bool **visited=(bool **)malloc(N*sizeof(bool *));
		int *queue=(int *)malloc(N*N*sizeof(int)), front=0, rear=0, previous_eaten=eaten, previous_size=size, count=0;
		for(int n=0;n<N;n++)
			visited[n]=(bool *)calloc(N,sizeof(bool));

		visited[y][x]=true;
		queue[rear++]=100*y+x;

		while(front<rear)
		{
			int previous_rear=rear, previous_front=front, able=0;

			if(front==0)
				previous_front++;

			while(front<previous_rear)
			{
				int temp_y=queue[front]/100, temp_x=queue[front]%100;

				if(space[temp_y][temp_x]>0 && space[temp_y][temp_x]<size)
					able++;

				if(able==0)
				{
					if(temp_x>0 && !visited[temp_y][temp_x-1] && space[temp_y][temp_x-1]<=size)
					{
						visited[temp_y][temp_x-1]=true;
						queue[rear++]=100*temp_y+temp_x-1;
					}
					if(temp_y>0 && !visited[temp_y-1][temp_x] && space[temp_y-1][temp_x]<=size)
					{
						visited[temp_y-1][temp_x]=true;
						queue[rear++]=100*(temp_y-1)+temp_x;
					}
					if(temp_x<N-1 && !visited[temp_y][temp_x+1] && space[temp_y][temp_x+1]<=size)
					{
						visited[temp_y][temp_x+1]=true;
						queue[rear++]=100*temp_y+temp_x+1;
					}
					if(temp_y<N-1 && !visited[temp_y+1][temp_x] && space[temp_y+1][temp_x]<=size)
					{
						visited[temp_y+1][temp_x]=true;
						queue[rear++]=100*(temp_y+1)+temp_x;
					}
				}
				front++;
			}

			if(able>0)
			{
				int next_x=100, next_y=100;

				for(int i=previous_front;i<previous_rear;i++)
				{
					int temp_y=queue[i]/100, temp_x=queue[i]%100;
					if(space[temp_y][temp_x]>0 && space[temp_y][temp_x]<size && (temp_y<next_y || temp_y==next_y&&temp_x<next_x))
					{
						next_x=temp_x;
						next_y=temp_y;
					}
				}

				sec+=count;
				total--;
				eaten++;
				if(eaten>=size)
				{
					if(size<7)
						total+=fish[size];
					size++;
					eaten=0;
				}
				space[next_y][next_x]=0;
				y=next_y;
				x=next_x;
				break;
			}

			count++;
		}

		for(int n=0;n<N;n++)
			free(visited[n]);
		free(visited);
		free(queue);

		if(previous_eaten==eaten && previous_size==size)
			break;
	}

	printf("%d\n", sec);
	for(int n=0;n<N;n++)
		free(space[n]);
	free(space);
	return 0;
}