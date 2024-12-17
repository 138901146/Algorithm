#include<stdio.h>
#include<stdbool.h>

int queue[1000001];
bool planet[1000][1000], visited[1000][1000]={0};

int main(void)
{
	int N, M, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, count=0;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			scanf("%d", &planet[n][m]);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			if(!planet[n][m] && !visited[n][m])
			{
				int front=0, rear=1;

				++count;
				visited[n][m]=true;

				queue[0]=n<<10|m;

				while(front<rear)
				{
					int r=queue[front]>>10, c=queue[front]&1023;

					for(int i=0;i<4;++i)
					{
						int nr=r+dr[i], nc=c+dc[i];

						if(nr<0)
							nr+=N;
						else if(N<=nr)
							nr-=N;

						if(nc<0)
							nc+=M;
						else if(M<=nc)
							nc-=M;

						if(!planet[nr][nc] && !visited[nr][nc])
						{
							visited[nr][nc]=true;
							queue[rear++]=nr<<10|nc;
						}
					}

					++front;
				}
			}

	printf("%d", count);
	return 0;
}