#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, K, **board=NULL, min=100000000;
	char *str=NULL;

	scanf("%d%d%d", &N, &M, &K);
	board=(int **)malloc((N+1)*sizeof(int *));
	str=(char *)calloc(M+1,sizeof(char));

	board[0]=(int *)calloc(M+1,sizeof(int));

	getchar();
	for(int n=1;n<=N;++n)
	{
		scanf("%s", str);
		board[n]=(int *)calloc(M+1,sizeof(int));

		for(int m=1;m<=M;++m)
		{
			board[n][m]=((n^m)&1?str[m-1]=='B':str[m-1]=='W')+board[n-1][m]+board[n][m-1]-board[n-1][m-1];

			if(K<=n && K<=m)
			{
				int area=board[n][m]-board[n-K][m]-board[n][m-K]+board[n-K][m-K];
				area=area<K*K-area?area:K*K-area;
				min=area<min?area:min;
			}
		}
	}

	printf("%d", min);
	for(int n=0;n<=N;++n)
		free(board[n]);
	free(board);
	free(str);
	return 0;
}