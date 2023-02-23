#include<stdio.h>
#include<stdlib.h>

char **board=NULL;
int R, C;

int max_move(int x,int y,int bit)
{
	int move[4]={0, }, max=0;

	for(int i=0;i<26;i++)
		if(bit&1<<i)
			max++;

	if(x>0 && (bit&(1<<(board[x-1][y]-'A')))==0)
		move[0]=max_move(x-1,y,bit|1<<(board[x-1][y]-'A'));
	if(x<R-1 && (bit&(1<<(board[x+1][y]-'A')))==0)
		move[1]=max_move(x+1,y,bit|1<<(board[x+1][y]-'A'));
	if(y>0 && (bit&(1<<(board[x][y-1]-'A')))==0)
		move[2]=max_move(x,y-1,bit|1<<(board[x][y-1]-'A'));
	if(y<C-1 && (bit&(1<<(board[x][y+1]-'A')))==0)
		move[3]=max_move(x,y+1,bit|1<<(board[x][y+1]-'A'));

	for(int i=0;i<4;i++)
		if(move[i]>max)
			max=move[i];

	return max;
}
int main(void)
{
	scanf("%d%d", &R, &C);
	board=(char **)malloc(R*sizeof(char *));
	for(int r=0;r<R;r++)
	{
		getchar();
		board[r]=(char *)calloc(C+1,sizeof(char));

		for(int c=0;c<C;c++)
			scanf("%c", &board[r][c]);
	}

	printf("%d\n", max_move(0,0,1<<(board[0][0]-'A')));
	for(int r=0;r<R;r++)
		free(board[r]);
	free(board);
	return 0;
}