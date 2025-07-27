#include<stdio.h>

int main(void)
{
	int board[5][5], r, c, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, queue[25], front=0, rear=1, min[5][5];

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			scanf("%d", &board[i][j]);
	scanf("%d%d", &r, &c);

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			min[i][j]=99;
	queue[0]=r<<3|c;
	min[r][c]=0;

	while(front<rear)
	{
		r=queue[front]>>3;
		c=queue[front]&7;

		for(int i=0;i<4;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0||4<next_r||next_c<0||4<next_c||board[next_r][next_c]==-1||min[next_r][next_c]!=99)
				continue;

			if(board[next_r][next_c]==1)
			{
				printf("%d", min[r][c]+1);
				return 0;
			}

			min[next_r][next_c]=min[r][c]+1;
			queue[rear++]=next_r<<3|next_c;
		}

		++front;
	}

	printf("-1");
	return 0;
}