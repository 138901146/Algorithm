#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, move[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}, **board=NULL, *queue=NULL, front=0, rear=1, row, col;

	scanf("%d%d", &N, &M);
	queue=(int *)malloc(N*N*sizeof(int));
	board=(int **)malloc((N+1)*sizeof(int *));
	for(int r=1;r<=N;++r)
	{
		board[r]=(int *)malloc((N+1)*sizeof(int));
		for(int c=1;c<=N;++c)
			board[r][c]=-1;
	}

	scanf("%d%d", &row, &col);
	queue[0]=row<<9|col;
	board[row][col]=0;

	while(M--)
	{
		scanf("%d%d", &row, &col);

		while(board[row][col]==-1)
		{
			int r=queue[front]>>9, c=queue[front]&511;

			for(int i=0;i<8;++i)
			{
				int dr=r+move[i][0], dc=c+move[i][1];

				if(0<dr && dr<=N && 0<dc && dc<=N && board[dr][dc]==-1)
				{
					board[dr][dc]=board[r][c]+1;
					queue[rear++]=dr<<9|dc;
				}
			}

			++front;
		}

		printf("%d ", board[row][col]);
	}

	for(int n=1;n<=N;++n)
		free(board[n]);
	free(board);
	free(queue);
	return 0;
}