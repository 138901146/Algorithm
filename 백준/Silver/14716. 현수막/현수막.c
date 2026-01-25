#include<stdio.h>
#include<stdbool.h>

int id[250][250]={0}, queue[62500];
bool banner[250][250];

int main(void)
{
	int M, N, count=0, dr[8]={-1,-1,0,1,1,1,0,-1}, dc[8]={0,1,1,1,0,-1,-1,-1};

	scanf("%d%d", &M, &N);

	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &banner[i][j]);

	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			if(banner[i][j]&&!id[i][j])
			{
				int front=0, rear=1;

				id[i][j]=++count;
				queue[0]=i<<8|j;

				while(front<rear)
				{
					int r=queue[front]>>8, c=queue[front]&255;

					for(int k=0;k<8;++k)
					{
						int next_r=r+dr[k], next_c=c+dc[k];

						if(next_r<0||M<=next_r||next_c<0||N<=next_c||!banner[next_r][next_c]||id[next_r][next_c])
							continue;

						id[next_r][next_c]=count;
						queue[rear++]=next_r<<8|next_c;
					}

					++front;
				}
			}

	printf("%d", count);
	return 0;
}