#include<stdio.h>

int main(void)
{
	int N, count=0, dr[8]={-1,-1,0,1,1,1,0,-1}, dc[8]={0,1,1,1,0,-1,-1,-1};
	char grid[100][101]={0}, word[5]={'M','O','B','I','S'};

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%s", grid[n]);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			if(grid[r][c]=='M')
			{
				int state=1;

				for(int i=0;i<8;++i)
				{
					int state=1;

					for(int j=1;j<5;++j,++state)
					{
						int nr=r+j*dr[i], nc=c+j*dc[i];

						if(nr<0||N<=nr||nc<0||N<=nc||grid[nr][nc]!=word[state])
							break;
					}

					count+=state==5;
				}
			}

	printf("%d", count);
	return 0;
}