#include<stdio.h>

#define INF 123456789

int map[1002][1002]={0}, total[1002][1002][3]={0};

int max(int r,int c)
{
	return total[r][c][1]<=total[r][c][0]&&total[r][c][2]<=total[r][c][0]?total[r][c][0]:total[r][c][0]<=total[r][c][1]&&total[r][c][2]<=total[r][c][1]?total[r][c][1]:total[r][c][2];
}

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	for(int m=1;m<=M;++m)
	{
		scanf("%d", &map[1][m]);
		total[1][m][0]=total[1][m][1]=total[1][m][2]=total[1][m-1][0]+map[1][m];
	}

	for(int n=2;n<=N;++n)
	{
		total[n][0][0]=total[n][0][1]=total[n][0][2]=total[n][M+1][0]=total[n][M+1][1]=total[n][M+1][2]=-INF;

		for(int m=1;m<=M;++m)
		{
			scanf("%d", &map[n][m]);

			total[n][m-1][2]=-INF;
			total[n][m][0]=map[n][m]+max(n-1,m);
			total[n][m][1]=map[n][m]+max(n,m-1);
		}

		for(int m=M;m;--m)
			total[n][m][2]=map[n][m]+(total[n][m+1][0]<total[n][m+1][2]?total[n][m+1][2]:total[n][m+1][0]);
	}

	printf("%d", max(N,M));
	return 0;
}