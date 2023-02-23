#include<stdio.h>

int main(void)
{
	int board[9][9], x=0, y=0;

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			scanf("%d", &board[i][j]);

			if(board[i][j]>board[x][y])
			{
				x=i;
				y=j;
			}
		}

	printf("%d\n%d %d\n", board[x][y], x+1, y+1);
	return 0;
}