#include<stdio.h>
#include<stdlib.h>

int min(int x,int y,int z)
{
	return x<=y&&x<=z?x:y<=x&&y<=z?y:z;
}

int main(void)
{
	int n, m, **board=NULL, max=0;

	scanf("%d %d", &n, &m);
	board=(int **)malloc((n+1)*sizeof(int *));
	for(int i=0;i<=n;i++)
		board[i]=(int *)calloc(m+1,sizeof(int));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%1d", &board[i][j]);

			if(board[i][j]==1)
				board[i][j]=min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1;

			max=board[i][j]>max?board[i][j]:max;
		}

	printf("%d\n", max*max);
	for(int i=0;i<=n;i++)
		free(board[i]);
	free(board);
	return 0;
}