#include<stdio.h>
#include<stdbool.h>

bool grid[1000][1000], visited[1000][1000]={false, };
int queue[1000000];

int main(void)
{
	int N, M, front=0, rear=0, dr[4]={-1, 0, 0, 1}, dc[4]={0, -1, 1, 0};

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			scanf("%1d", &grid[n][m]);

	for(int m=0;m<M;++m)
		if(!grid[0][m])
		{
			visited[0][m]=true;
			queue[rear++]=m;
		}

	while(front<rear)
	{
		int r=queue[front]>>10, c=queue[front]&1023;

		for(int i=0;i<4;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0 || N<=next_r || next_c<0 || M<=next_c || grid[next_r][next_c] || visited[next_r][next_c])
				continue;

			if(next_r==N-1)
			{
				printf("YES");
				return 0;
			}

			visited[next_r][next_c]=true;
			queue[rear++]=next_r<<10|next_c;
		}

		++front;
	}

	printf("NO");
	return 0;
}