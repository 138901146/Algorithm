#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int H, N;
	long **board=NULL;

	scanf("%d%d", &H, &N);

	if(H==N)
	{
		printf("1\n");
		return 0;
	}
	if(H>N)
	{
		H+=N;
		N=H-N;
		H-=N;
	}
	N-=H;
	H=0;

	board=(long **)malloc((N+2)*sizeof(long *));
	for(int n=0;n<N+2;n++)
		board[n]=(long *)calloc(N+2,sizeof(long));

	for(int i=1;i<N+2;i++)
	{
		board[0][i]=1;
		for(int j=1;j<=i;j++)
			board[i][j]=board[i-1][j]+board[i][j-1];
	}

	printf("%ld\n", board[N+1][N+1]);
	for(int n=0;n<N+2;n++)
		free(board[n]);
	free(board);
	return 0;
}