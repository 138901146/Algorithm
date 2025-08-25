#include<stdio.h>

int main(void)
{
	int N, dr[4]={-1,-1,0,1}, dc[4]={0,1,1,1};
	char board[30][31]={0};

	scanf("%d", &N);
	for(int r=0;r<N;++r)
		scanf("%s", board[r]);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			if(board[r][c]!='.')
				for(int i=0;i<4;++i)
				{
					int nr=r+dr[i], nc=c+dc[i];

					if(nr<0||N<=nr||nc<0||N<=nc||board[r][c]!=board[nr][nc])
						continue;

					nr=r-dr[i];
					nc=c-dc[i];

					if(nr<0||N<=nr||nc<0||N<=nc||board[r][c]!=board[nr][nc])
						continue;

					printf("%c", board[r][c]);
					return 0;
				}

	printf("ongoing");
	return 0;
}