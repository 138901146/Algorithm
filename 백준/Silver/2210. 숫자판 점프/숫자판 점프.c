#include<stdio.h>
#include<stdbool.h>

bool check[1000000]={false};
int board[5][5], count=0, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void simulate(int row,int col,int current,int total)
{
	if(current==5)
	{
		if(!check[total])
		{
			++count;
			check[total]=true;
		}
		return;
	}

	for(int i=0;i<4;++i)
	{
		row+=move[i][0];
		col+=move[i][1];

		if(row>=0 && row<5 && col>=0 && col<5)
			simulate(row,col,current+1,total*10+board[row][col]);

		row-=move[i][0];
		col-=move[i][1];
	}
}

int main(void)
{
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			scanf("%d", &board[i][j]);

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			simulate(i,j,0,board[i][j]);

	printf("%d", count);
	return 0;
}