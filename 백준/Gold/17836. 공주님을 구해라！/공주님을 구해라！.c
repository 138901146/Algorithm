#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, T, castle[100][100], distance[100][100]={0}, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, gram=-1, queue[10001], front=0, rear=1, r, c;
	bool visited[100][100]={false};

	scanf("%d%d%d", &N, &M, &T);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			scanf("%d", &castle[n][m]);

	queue[0]=0;
	visited[0][0]=true;

	while(front<rear)
	{
		r=queue[front]>>7;
		c=queue[front]&127;

		for(int i=0;i<4;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0 || N<=next_r || next_c<0 || M<=next_c || castle[next_r][next_c]==1 || visited[next_r][next_c])
				continue;
			else if(castle[next_r][next_c]==2)
				gram=next_r<<7|next_c;

			visited[next_r][next_c]=true;
			distance[next_r][next_c]=distance[r][c]+1;
			queue[rear++]=next_r<<7|next_c;
		}

		++front;
	}

	r=gram>>7;
	c=gram&127;

	if(distance[r][c])
	{
		if(distance[N-1][M-1])
			distance[N-1][M-1]=distance[r][c]+N-r+M-c-2<distance[N-1][M-1]?distance[r][c]+N-r+M-c-2:distance[N-1][M-1];
		else
			distance[N-1][M-1]=distance[r][c]+N-r+M-c-2;
	}

	if(distance[N-1][M-1] && distance[N-1][M-1]<=T)
		printf("%d", distance[N-1][M-1]);
	else
		printf("Fail");
	return 0;
}