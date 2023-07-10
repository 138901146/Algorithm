#include<stdio.h>
#include<stdbool.h>

int board[9][9], empty[81], count=0;
bool found=false;

bool check(void)
{
	for(int i=0;i<9;i++)
	{
		bool row[9]={false, }, col[9]={false, };

		for(int j=0;j<9;j++)
		{
			if(board[i][j]==0 || board[j][i]==0)
				return false;
			if(row[board[i][j]-1])
				return false;
			row[board[i][j]-1]=true;
			if(col[board[j][i]-1])
				return false;
			col[board[j][i]-1]=true;
		}
	}

	for(int y=0;y<3;y++)
		for(int x=0;x<3;x++)
		{
			bool adjacent[9]={false, };

			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
				{
					if(adjacent[board[y*3+i][x*3+j]-1])
						return false;
					adjacent[board[y*3+i][x*3+j]-1]=true;
				}
		}

	return true;
}

void sudoku(int current)
{
	if(found)
		return;
	if(current==count)
	{
		if(check())
		{
			found=true;
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					printf("%d ", board[i][j]);
				printf("\n");
			}
		}

		return;
	}

	int y=empty[current]>>4, x=empty[current]&15;
	bool row[9]={false, }, col[9]={false, }, adjacent[9]={false, };

	for(int i=0;i<9;i++)
	{
		if(board[y][i]!=0)
		{
			if(row[board[y][i]-1])
				return;
			row[board[y][i]-1]=true;
		}
		if(board[i][x]!=0)
		{
			if(col[board[i][x]-1])
				return;
			col[board[i][x]-1]=true;
		}
		if(board[y-y%3+i/3][x-x%3+i%3]!=0)
		{
			if(adjacent[board[y-y%3+i/3][x-x%3+i%3]-1])
				return;
			adjacent[board[y-y%3+i/3][x-x%3+i%3]-1]=true;
		}
	}

	for(int i=0;i<9;i++)
		if(!row[i] && !col[i] && !adjacent[i])
		{
			board[y][x]=i+1;
			sudoku(current+1);
		}
	board[y][x]=0;
}

int main(void)
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			scanf("%d", &board[i][j]);
			if(board[i][j]==0)
				empty[count++]=i<<4|j;
		}

	sudoku(0);
	return 0;
}