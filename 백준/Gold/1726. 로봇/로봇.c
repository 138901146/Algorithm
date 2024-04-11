#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int M, N, operation[101][101][4]={0}, start_row, start_col, start_dir, end_row, end_col, end_dir, move_r[4]={-1,0,0,1}, move_c[4]={0,1,-1,0}, queue[40000], front=0, rear=1, direction_map[4][2]={{1,2},{0,3},{0,3},{1,2}};
	bool board[101][101];

	scanf("%d%d", &M, &N);

	for(int m=1;m<=M;++m)
		for(int n=1;n<=N;++n)
			scanf("%d", &board[m][n]);

	scanf("%d%d%d", &start_row, &start_col, &start_dir);
	scanf("%d%d%d", &end_row, &end_col, &end_dir);

	start_dir&=3;
	end_dir&=3;

	operation[start_row][start_col][start_dir]=1;
	queue[0]=start_row<<9|start_col<<2|start_dir;

	while(!operation[end_row][end_col][end_dir])
	{
		int r=queue[front]>>9, c=(queue[front]&511)>>2, d=queue[front]&3;

		for(int i=0;i<2;++i)
			if(!operation[r][c][direction_map[d][i]])
			{
				operation[r][c][direction_map[d][i]]=operation[r][c][d]+1;
				queue[rear++]=r<<9|c<<2|direction_map[d][i];
			}

		for(int k=1;k<4;++k)
		{
			int next_row=r+k*move_r[d], next_col=c+k*move_c[d];

			if(next_row<=0 || M<next_row || next_col<=0 || N<next_col || operation[next_row][next_col][d])
				continue;

			if(board[next_row][next_col])
				break;

			operation[next_row][next_col][d]=operation[r][c][d]+1;
			queue[rear++]=next_row<<9|next_col<<2|d;
		}

		++front;
	}

	printf("%d", operation[end_row][end_col][end_dir]-1);
	return 0;
}