#include<stdio.h>

int stone[1001][1002], score[1001][1002][4][2]={0};

int main(void)
{
	int N, max=0;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			scanf("%d", &stone[i][j]);

			if(stone[i][j]==1)
			{
				score[i][j][0][0]=score[i][j-1][0][0]+1;
				score[i][j][1][0]=score[i-1][j][1][0]+1;
				score[i][j][2][0]=score[i-1][j-1][2][0]+1;
				score[i][j][3][0]=score[i-1][j+1][3][0]+1;
				score[i][j][0][1]=(score[i][j-1][0][0]<score[i][j-1][0][1]?score[i][j-1][0][1]:score[i][j-1][0][0])+1;
				score[i][j][1][1]=(score[i-1][j][1][0]<score[i-1][j][1][1]?score[i-1][j][1][1]:score[i-1][j][1][0])+1;
				score[i][j][2][1]=(score[i-1][j-1][2][0]<score[i-1][j-1][2][1]?score[i-1][j-1][2][1]:score[i-1][j-1][2][0])+1;
				score[i][j][3][1]=(score[i-1][j+1][3][0]<score[i-1][j+1][3][1]?score[i-1][j+1][3][1]:score[i-1][j+1][3][0])+1;
			}
			else if(stone[i][j]==2)
			{
				score[i][j][0][1]=score[i][j-1][0][0]+1;
				score[i][j][1][1]=score[i-1][j][1][0]+1;
				score[i][j][2][1]=score[i-1][j-1][2][0]+1;
				score[i][j][3][1]=score[i-1][j+1][3][0]+1;
			}

			for(int k=0;k<4;++k)
				for(int l=0;l<2;++l)
					max=score[i][j][k][l]<max?max:score[i][j][k][l];
		}

	printf("%d", max);
	return 0;
}