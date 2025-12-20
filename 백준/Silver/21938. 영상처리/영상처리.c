#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, M, T, R, G, B, **pixel=NULL, *queue=NULL, object=0, dr[4]={-1,0,0,1}, dc[4]={0,1,-1,0};
	bool **display=NULL, **visited=NULL;

	scanf("%d%d", &N, &M);
	pixel=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;++i)
	{
		pixel[i]=(int *)malloc(M*sizeof(int));
		for(int j=0;j<M;++j)
		{
			scanf("%d%d%d", &R, &G, &B);
			pixel[i][j]=R+G+B;
		}
	}

	scanf("%d", &T);

	display=(bool **)malloc(N*sizeof(bool *));
	visited=(bool **)malloc(N*sizeof(bool *));
	for(int i=0;i<N;++i)
	{
		display[i]=(bool *)calloc(M,sizeof(bool));
		visited[i]=(bool *)calloc(M,sizeof(bool));
		for(int j=0;j<M;++j)
			if(T*3<=pixel[i][j])
				display[i][j]=true;
		free(pixel[i]);
	}
	free(pixel);

	queue=(int *)malloc(N*M*sizeof(int));
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(display[i][j]&&!visited[i][j])
			{
				int front=0, rear=1;

				++object;
				visited[i][j]=true;
				queue[0]=i<<10|j;

				while(front<rear)
				{
					int r=queue[front]>>10, c=queue[front]&1023;

					for(int k=0;k<4;++k)
					{
						int next_r=r+dr[k], next_c=c+dc[k];

						if(next_r<0||N<=next_r||next_c<0||M<=next_c||!display[next_r][next_c]||visited[next_r][next_c])
							continue;

						visited[next_r][next_c]=true;
						queue[rear++]=next_r<<10|next_c;
					}

					++front;
				}
			}

	printf("%d", object);
	for(int i=0;i<N;++i)
	{
		free(display[i]);
		free(visited[i]);
	}
	free(display);
	free(visited);
	free(queue);
	return 0;
}