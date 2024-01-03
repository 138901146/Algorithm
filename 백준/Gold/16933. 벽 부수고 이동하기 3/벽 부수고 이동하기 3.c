#include<stdio.h>
#include<stdbool.h>

int distance[1000][1000][11][2], queue[1000000];
bool wall[1000][1000];

int main(void)
{
	int N, M, K, front=0, rear=1, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, min=1000000000;

	scanf("%d%d%d", &N, &M, &K);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
		{
			scanf("%1d", &wall[n][m]);
			for(int k=0;k<=K;++k)
				distance[n][m][k][0]=distance[n][m][k][1]=1000000000;
		}

	queue[0]=0;
	distance[0][0][0][0]=1;
	while(front<rear)
	{
		int r=queue[front%1000000]>>15, c=queue[front%1000000]>>5&1023, broke=queue[front%1000000]>>1&15, night=queue[front%1000000]&1;

		for(int i=0;i<4;++i)
		{
			int next_r=r+move[i][0], next_c=c+move[i][1];

			if(next_r<0 || next_r>=N || next_c<0 || next_c>=M)
				continue;

			if(wall[next_r][next_c])
			{
				if(broke==K || night)
					continue;

				if(distance[next_r][next_c][broke+1][1]>distance[r][c][broke][0]+1)
				{
					distance[next_r][next_c][broke+1][1]=distance[r][c][broke][0]+1;
					queue[rear++%1000000]=next_r<<15|next_c<<5|broke+1<<1|1;
				}
			}
			else
			{
				if(distance[next_r][next_c][broke][!night]>distance[r][c][broke][night]+1)
				{
					distance[next_r][next_c][broke][!night]=distance[r][c][broke][night]+1;
					queue[rear++%1000000]=next_r<<15|next_c<<5|broke<<1|!night;
				}
			}
		}

		if(distance[r][c][broke][!night]>distance[r][c][broke][night]+1)
		{
			distance[r][c][broke][!night]=distance[r][c][broke][night]+1;
			queue[rear++%1000000]=r<<15|c<<5|broke<<1|!night;
		}

		++front;
	}

	for(int k=0;k<=K;++k)
		for(int night=0;night<2;++night)
			min=distance[N-1][M-1][k][night]<min?distance[N-1][M-1][k][night]:min;

	printf("%d", min==1000000000?-1:min);
	return 0;
}