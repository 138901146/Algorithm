#include<stdio.h>
#include<stdbool.h>

#define INF 9999

int main(void)
{
	int N, M, map[50][50], virus[10], virus_count=0, wall_count=0, min=INF, queue[2500], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};

	scanf("%d%d", &N, &M);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			scanf("%d", &map[r][c]);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			if(map[r][c]==1)
				++wall_count;
			else if(map[r][c]==2)
				virus[virus_count++]=r<<6|c;

	for(int initial=1;initial<(1<<virus_count);++initial)
	{
		int m=0, front=0, rear=0, count=-1;
		bool visited[50][50]={false};

		for(int i=0;i<virus_count;++i)
			if(1<<i&initial)
				++m;

		if(M<m)
			continue;

		for(int i=0;i<virus_count;++i)
			if(1<<i&initial)
			{
				queue[rear++]=virus[i];
				visited[virus[i]>>6][virus[i]&63]=true;
			}
			else
				map[virus[i]>>6][virus[i]&63]=0;

		while(front<rear)
		{
			int previous_rear=rear;

			while(front<previous_rear)
			{
				int r=queue[front]>>6, c=queue[front]&63;

				for(int i=0;i<4;++i)
				{
					int next_r=r+dr[i], next_c=c+dc[i];

					if(next_r<0||N<=next_r||next_c<0||N<=next_c||visited[next_r][next_c]||map[next_r][next_c]==1)
						continue;

					visited[next_r][next_c]=true;
					queue[rear++]=next_r<<6|next_c;
				}

				++front;
			}

			++count;
		}

		if(rear==N*N-wall_count)
			min=count<min?count:min;

		for(int i=0;i<virus_count;++i)
			map[virus[i]>>6][virus[i]&63]=2;
	}

	printf("%d", min==INF?-1:min);
	return 0;
}