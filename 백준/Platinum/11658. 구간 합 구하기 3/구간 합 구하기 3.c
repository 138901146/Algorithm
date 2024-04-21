#include<stdio.h>

int board[1025][1025], prefix_sum[1025][1025]={0};

int main(void)
{
	int N, M, w;

	scanf("%d%d", &N, &M);

	for(int r=1;r<=N;++r)
		for(int c=1;c<=N;++c)
		{
			scanf("%d", &board[r][c]);
			prefix_sum[r][c]=prefix_sum[r][c-1]+board[r][c];
		}

	while(M--)
	{
		scanf("%d", &w);

		if(w)
		{
			int x1, y1, x2, y2, sum=0;

			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

			for(int r=x1;r<=x2;++r)
				sum+=prefix_sum[r][y2]-prefix_sum[r][y1-1];

			printf("%d\n", sum);
		}
		else
		{
			int x, y, c, diff;

			scanf("%d%d%d", &x, &y, &c);

			diff=c-board[x][y];
			board[x][y]=c;

			for(int c=y;c<=N;++c)
				prefix_sum[x][c]+=diff;
		}
	}

	return 0;
}