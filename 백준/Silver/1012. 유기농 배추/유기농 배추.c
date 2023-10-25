#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int T, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

	scanf("%d", &T);

	while(T--)
	{
		int M, N, K, X, Y, queue[2500], count=0;
		bool farm[50][50]={false};

		scanf("%d%d%d", &M, &N, &K);

		while(K--)
		{
			scanf("%d%d", &X, &Y);
			farm[Y][X]=true;
		}

		for(int r=0;r<N;++r)
			for(int c=0;c<M;++c)
				if(farm[r][c])
				{
					int front=0, rear=1;

					++count;
					farm[r][c]=false;
					queue[0]=r<<6|c;

					while(front<rear)
					{
						int y=queue[front]>>6, x=queue[front]&63;

						for(int i=0;i<4;++i)
						{
							y+=move[i][0];
							x+=move[i][1];

							if(y>=0 && y<N && x>=0 && x<M && farm[y][x])
							{
								farm[y][x]=false;
								queue[rear++]=y<<6|x;
							}

							y-=move[i][0];
							x-=move[i][1];
						}

						++front;
					}
				}

		printf("%d\n", count);
	}

	return 0;
}