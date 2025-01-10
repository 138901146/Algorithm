#include<stdio.h>

#define INF 1000000

int grid[500][500], min[500][500], queue[250000];

int main(void)
{
	int n, m, front=0, rear=1, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};

	scanf("%d%d", &n, &m);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			scanf("%1d", &grid[i][j]);
			min[i][j]=INF;
		}

	min[0][0]=0;
	queue[0]=0;

	while(front<rear && min[n-1][m-1]==INF)
	{
		int r=queue[front]>>9, c=queue[front]&511;

		for(int i=0;i<4;++i)
		{
			int next_r=r+grid[r][c]*dr[i], next_c=c+grid[r][c]*dc[i];

			if(0<=next_r && next_r<n && 0<=next_c && next_c<m && min[next_r][next_c]==INF)
			{
				min[next_r][next_c]=min[r][c]+1;
				queue[rear++]=next_r<<9|next_c;
			}
		}

		++front;
	}

	if(min[n-1][m-1]==INF)
		printf("IMPOSSIBLE");
	else
		printf("%d", min[n-1][m-1]);
	return 0;
}