#include<stdio.h>

int main(void)
{
	int test_case, l, row_start, row_end, col_start, col_end, queue[90000], dr[8]={-2,-1,1,2,2,1,-1,-2}, dc[8]={1,2,2,1,-1,-2,-2,-1};

	scanf("%d", &test_case);

	while(test_case--)
	{
		int front=0, rear=1, move[300][300]={0};

		scanf("%d", &l);
		scanf("%d%d", &row_start, &col_start);
		scanf("%d%d", &row_end, &col_end);

		move[row_start][col_start]=1;
		queue[0]=row_start<<9|col_start;

		while(!move[row_end][col_end])
		{
			int r=queue[front]>>9, c=queue[front]&511;

			for(int i=0;i<8;++i)
			{
				int next_row=r+dr[i], next_col=c+dc[i];

				if(next_row<0 || l<=next_row || next_col<0 || l<=next_col || move[next_row][next_col])
					continue;

				move[next_row][next_col]=move[r][c]+1;
				queue[rear++]=next_row<<9|next_col;
			}

			++front;
		}

		printf("%d\n", move[row_end][col_end]-1);
	}

	return 0;
}