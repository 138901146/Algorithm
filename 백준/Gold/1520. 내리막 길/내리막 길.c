#include<stdio.h>

int M, N, board[501][501], method[501][501], move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int find_method(int y,int x)
{
	if(method[y][x]!=-1)
		return method[y][x];

	method[y][x]=0;
	for(int i=0;i<4;i++)
	{
		int dy=y+move[i][0], dx=x+move[i][1];

		if(dy>=0 && dy<M && dx>=0 && dx<N && board[dy][dx]>board[y][x])
			method[y][x]+=find_method(dy,dx);
	}

	return method[y][x];
}

int main(void)
{
	scanf("%d%d", &M, &N);

	for(int m=0;m<M;m++)
		for(int n=0;n<N;n++)
		{
			scanf("%d", &board[m][n]);
			method[m][n]=-1;
		}

	method[0][0]=1;
	printf("%d\n", find_method(M-1,N-1));
	return 0;
}