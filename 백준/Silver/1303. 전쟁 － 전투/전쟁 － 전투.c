#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, M, *queue=NULL, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, blue=0, white=0;
	bool **visited=NULL;
	char **battleground=NULL;

	scanf("%d%d", &N, &M);
	battleground=(char **)malloc(M*sizeof(char *));
	visited=(bool **)malloc(M*sizeof(bool *));
	queue=(int *)malloc(N*M*sizeof(int));

	for(int m=0;m<M;++m)
	{
		battleground[m]=(char *)calloc(N+1,sizeof(char));
		visited[m]=(bool *)calloc(N,sizeof(bool));

		scanf("%s", battleground[m]);
	}

	for(int m=0;m<M;++m)
		for(int n=0;n<N;++n)
			if(!visited[m][n])
			{
				int front=0, rear=1;

				queue[0]=m<<7|n;
				visited[m][n]=true;

				while(front<rear)
				{
					int r=queue[front]>>7, c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						int next_r=r+move[i][0], next_c=c+move[i][1];

						if(next_r<0 || next_c<0 || M<=next_r || N<=next_c || visited[next_r][next_c] || battleground[m][n]!=battleground[next_r][next_c])
							continue;

						visited[next_r][next_c]=true;
						queue[rear++]=next_r<<7|next_c;
					}

					++front;
				}

				if(battleground[m][n]=='W')
					white+=rear*rear;
				else
					blue+=rear*rear;
			}

	printf("%d %d", white, blue);
	for(int m=0;m<M;++m)
	{
		free(battleground[m]);
		free(visited[m]);
	}
	free(battleground);
	free(visited);
	free(queue);
	return 0;
}