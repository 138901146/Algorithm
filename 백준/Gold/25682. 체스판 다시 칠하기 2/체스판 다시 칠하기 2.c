#include<stdio.h>

int N, M, K, board[2001][2001]={0}, min=100000000;
char str[2001]={'\0'};

int main(void)
{

	scanf("%d%d%d", &N, &M, &K);

	getchar();
	for(int n=1;n<=N;++n)
	{
		scanf("%s", str);

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
	return 0;
}