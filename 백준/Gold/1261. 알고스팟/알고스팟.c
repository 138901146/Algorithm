#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, min[100][100], queue[16384], front=0, rear=1, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
	bool wall[100][100];

	scanf("%d%d", &M, &N);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
		{
			scanf("%1d", &wall[n][m]);
			min[n][m]=100000000;
		}

	queue[0]=min[0][0]=0;

	while(front<rear)
	{
		int r=queue[front&16383]>>7, c=queue[front&16383]&127;

		for(int i=0;i<4;++i)
			if(r+move[i][0]>=0 && r+move[i][0]<N && c+move[i][1]>=0 && c+move[i][1]<M && min[r+move[i][0]][c+move[i][1]]>min[r][c]+wall[r+move[i][0]][c+move[i][1]])
			{
				min[r+move[i][0]][c+move[i][1]]=min[r][c]+wall[r+move[i][0]][c+move[i][1]];
				queue[rear++&16383]=(r+move[i][0])<<7|c+move[i][1];
			}

		++front;
	}

	printf("%d", min[N-1][M-1]);
	return 0;
}