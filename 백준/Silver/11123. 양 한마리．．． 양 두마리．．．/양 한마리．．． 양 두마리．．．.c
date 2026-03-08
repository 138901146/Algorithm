#include<stdio.h>

int main(void)
{
	int T, queue[10000], dh[4]={-1,0,0,1}, dw[4]={0,-1,1,0};

	scanf("%d", &T);

	while(T--)
	{
		int H, W, id[100][100]={0}, count=0;
		char grid[100][101]={0};

		scanf("%d%d", &H, &W);

		for(int i=0;i<H;++i)
			scanf("%s", grid[i]);

		for(int i=0;i<H;++i)
			for(int j=0;j<W;++j)
				if(grid[i][j]=='#'&&!id[i][j])
				{
					int front=0, rear=1;

					id[i][j]=++count;
					queue[0]=i<<7|j;

					while(front<rear)
					{
						int h=queue[front]>>7, w=queue[front]&127;

						for(int k=0;k<4;++k)
						{
							int r=h+dh[k], c=w+dw[k];

							if(r<0||H<=r||c<0||W<=c||grid[r][c]!='#'||id[r][c])
								continue;

							id[r][c]=count;
							queue[rear++]=r<<7|c;
						}

						++front;
					}
				}

		printf("%d\n", count);
	}

	return 0;
}