#include<stdio.h>
#include<memory.h>

int main(void)
{
	int N, r1, c1, r2, c2, board[200][200], dr[6]={-2,-2,0,0,2,2}, dc[6]={-1,1,-2,2,-1,1}, queue[40000], front=0, rear=1;

	scanf("%d", &N);
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

	memset(board,-1,40000*sizeof(int));
	board[r1][c1]=0;
	queue[0]=r1<<8|c1;

	while(front<rear && board[r2][c2]==-1)
	{
		int r=queue[front]>>8, c=queue[front]&255;

		for(int i=0;i<6;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0 || N<=next_r || next_c<0 || N<=next_c || board[next_r][next_c]!=-1)
				continue;

			board[next_r][next_c]=board[r][c]+1;
			queue[rear++]=next_r<<8|next_c;
		}

		++front;
	}

	printf("%d", board[r2][c2]);
	return 0;
}