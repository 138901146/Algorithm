#include<stdio.h>
#include<stdbool.h>

#define INF 999

int main(void)
{
	int N, M, space[50][50], queue[2500], max=0, dr[8]={-1,-1,0,1,1,1,0,-1}, dc[8]={0,1,1,1,0,-1,-1,-1};

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			scanf("%d", &space[n][m]);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			if(!space[n][m])
			{
				int front=0, rear=1, count=1, distance=INF;
				bool visited[50][50]={false};

				queue[0]=n<<6|m;
				visited[n][m]=true;

				while(distance==INF)
				{
					int previous_rear=rear;

					while(front<previous_rear&&distance==INF)
					{
						int r=queue[front]>>6, c=queue[front]&63;

						for(int i=0;i<8;++i)
						{
							int next_r=r+dr[i], next_c=c+dc[i];

							if(next_r<0||N<=next_r||next_c<0||M<=next_c||visited[next_r][next_c])
								continue;
							else if(space[next_r][next_c])
							{
								distance=count;
								break;
							}
							visited[next_r][next_c]=true;
							queue[rear++]=next_r<<6|next_c;
						}

						++front;
					}

					++count;
				}

				max=distance<max?max:distance;
			}

	printf("%d", max);
	return 0;
}