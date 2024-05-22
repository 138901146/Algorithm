#include<stdio.h>

int main(void)
{
	int N, stone, score[2][1002][4][2]={0}, current=1, previous=0, max=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i, current^=1, previous^=1)
		for(int j=1;j<=N;++j)
		{
			scanf("%d", &stone);

			if(stone==1)
			{
				score[current][j][0][0]=score[current][j-1][0][0]+1;
				score[current][j][1][0]=score[previous][j][1][0]+1;
				score[current][j][2][0]=score[previous][j-1][2][0]+1;
				score[current][j][3][0]=score[previous][j+1][3][0]+1;
				score[current][j][0][1]=(score[current][j-1][0][0]<score[current][j-1][0][1]?score[current][j-1][0][1]:score[current][j-1][0][0])+1;
				score[current][j][1][1]=(score[previous][j][1][0]<score[previous][j][1][1]?score[previous][j][1][1]:score[previous][j][1][0])+1;
				score[current][j][2][1]=(score[previous][j-1][2][0]<score[previous][j-1][2][1]?score[previous][j-1][2][1]:score[previous][j-1][2][0])+1;
				score[current][j][3][1]=(score[previous][j+1][3][0]<score[previous][j+1][3][1]?score[previous][j+1][3][1]:score[previous][j+1][3][0])+1;
			}
			else if(stone==2)
			{
				score[current][j][0][0]=score[current][j][1][0]=score[current][j][2][0]=score[current][j][3][0]=0;
				score[current][j][0][1]=score[current][j-1][0][0]+1;
				score[current][j][1][1]=score[previous][j][1][0]+1;
				score[current][j][2][1]=score[previous][j-1][2][0]+1;
				score[current][j][3][1]=score[previous][j+1][3][0]+1;
			}
			else
				for(int k=0;k<4;++k)
					for(int l=0;l<2;++l)
						score[current][j][k][l]=0;

			for(int k=0;k<4;++k)
				for(int l=0;l<2;++l)
					max=score[current][j][k][l]<max?max:score[current][j][k][l];
		}

	printf("%d", max);
	return 0;
}