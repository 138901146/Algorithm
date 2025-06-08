#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, x, y;
	bool table[101][101]={false};

	scanf("%d", &N);
	scanf("%d", &M);

	while(M--)
	{
		scanf("%d%d", &x, &y);
		table[x][y]=true;
	}

	for(int n=1;n<=N;++n)
		table[n][n]=true;

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				table[start][end]|=table[start][mid]&&table[mid][end];

	for(int i=1;i<=N;++i)
	{
		int count=N;

		for(int j=1;j<=N;++j)
			count-=table[i][j]||table[j][i];

		printf("%d\n", count);
	}

	return 0;
}