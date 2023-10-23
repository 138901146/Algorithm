#include<stdio.h>

int main(void)
{
	int board[19][19], move[4][2]={{1,1},{0,1},{-1,1},{1,0}};

	for(int i=0;i<19;++i)
		for(int j=0;j<19;++j)
			scanf("%d", &board[i][j]);

	for(int i=0;i<19;++i)
		for(int j=0;j<19;++j)
			if(board[i][j])
				for(int k=0;k<4;++k)
				{
					int r=i, c=j, count=0;

					while(r>=0 && r<19 && c>=0 && c<19 && board[i][j]==board[r][c])
					{
						r+=move[k][0];
						c+=move[k][1];
					}
					r-=move[k][0];
					c-=move[k][1];

					while(r>=0 && r<19 && c>=0 && c<19 && board[i][j]==board[r][c])
					{
						r-=move[k][0];
						c-=move[k][1];
						++count;
					}

					if(count==5)
					{
						printf("%d\n%d %d", board[i][j], r+move[k][0]+1, c+move[k][1]+1);
						return 0;
					}
				}

	printf("0");
	return 0;
}