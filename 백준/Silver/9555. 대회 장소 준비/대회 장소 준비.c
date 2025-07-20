#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int T, dr[8]={-1,0,0,1,-1,-1,1,1}, dc[8]={0,-1,1,0,-1,1,-1,1}, queue[10000], venue[100][100], N, M;

	scanf("%d", &T);

	while(T--)
	{
		int count=0;
		bool visited[100][100]={false}, adjacent[101]={false};

		scanf("%d%d", &N, &M);

		for(int n=0;n<N;++n)
			for(int m=0;m<M;++m)
				scanf("%d", &venue[n][m]);

		for(int n=0;n<N;++n)
			for(int m=0;m<M;++m)
				if(venue[n][m]!=-1&&!visited[n][m])
				{
					int front=0, rear=1;

					visited[n][m]=true;
					queue[0]=n<<7|m;

					while(front<rear)
					{
						int r=queue[front]>>7, c=queue[front]&127;

						for(int i=0;i<8;++i)
						{
							int next_r=r+dr[i], next_c=c+dc[i];

							if(next_r<0||N<=next_r||next_c<0||M<=next_c||visited[next_r][next_c]||venue[r][c]!=venue[next_r][next_c])
								continue;

							visited[next_r][next_c]=true;
							queue[rear++]=next_r<<7|next_c;
						}

						++front;
					}

					if(1<rear)
						adjacent[venue[queue[0]>>7][queue[0]&127]]=true;
				}

		for(int team=1;team<=100;++team)
			count+=adjacent[team];

		printf("%d\n", count);
	}

	return 0;
}