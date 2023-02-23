#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, x, y, w, h, board[1001][1001]={1, }, *count=NULL, current=0;

	for(int i=0;i<1001;i++)
		for(int j=0;j<1001;j++)
			board[i][j]=-1;

	scanf("%d", &N);
	count=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d%d%d%d", &x, &y, &w, &h);
		for(int i=0;i<w;i++)
			for(int j=0;j<h;j++)
				board[x+i][y+j]=n;
	}

	for(int i=0;i<1001;i++)
		for(int j=0;j<1001;j++)
			if(board[i][j]!=-1)
				count[board[i][j]]++;

	for(int n=0;n<N;n++)
		printf("%d\n", count[n]);
	free(count);
	return 0;
}