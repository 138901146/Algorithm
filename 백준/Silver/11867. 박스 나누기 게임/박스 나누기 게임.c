#include<stdio.h>

int winner[101][101][2];

int simulate(int x,int y,int turn)
{
	int next=turn^1;

	if(x==1 && y==1)
		return winner[x][y][turn]=next;
	else if(x==2 || y==2)
		return winner[x][y][turn]=turn;
	else if(winner[x][y][turn]!=-1)
		return winner[x][y][turn];
	if(x>1)
		for(int i=1;i<x;i++)
			if(simulate(i,x-i,next)==turn)
				return winner[x][y][turn]=turn;
	if(y>1)
		for(int i=1;i<y;i++)
			if(simulate(i,y-i,next)==turn)
				return winner[x][y][turn]=turn;

	return winner[x][y][turn]=next;
}

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	for(int i=1;i<101;i++)
		for(int j=1;j<101;j++)
			winner[i][j][0]=winner[i][j][1]=-1;

	printf("%c\n", simulate(N,M,0)==0?'A':'B');
	return 0;
}