#include<stdio.h>

int main(void)
{
	int R, C, id[100][100]={0}, count=0, queue[10000], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	char grid[100][101]={0};

	scanf("%d%d", &R, &C);

	for(int r=0;r<R;++r)
		scanf("%s", grid[r]);

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(grid[r][c]=='#'&&!id[r][c])
			{
				int front=0, rear=1;

				id[r][c]=++count;
				queue[0]=r<<7|c;

				while(front<rear)
				{
					int current_r=queue[front]>>7, current_c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						int next_r=current_r+dr[i], next_c=current_c+dc[i];

						if(next_r<0||R<=next_r||next_c<0||C<=next_c||grid[next_r][next_c]=='.'||id[next_r][next_c])
							continue;

						id[next_r][next_c]=count;
						queue[rear++]=next_r<<7|next_c;
					}

					++front;
				}
			}

	printf("%d", count);
	return 0;
}