#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int main(void)
{
	int N, map[100][100], count=0, dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1}, queue[10000], min=200;
	bool visited[100][100]={false};

	scanf("%d", &N);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			scanf("%d", &map[r][c]);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			if(map[r][c]&&!visited[r][c])
			{
				int front=0, rear=1;
				map[r][c]=++count;
				visited[r][c]=true;
				queue[0]=r<<7|c;

				while(front<rear)
				{
					int current_r=queue[front]>>7, current_c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						int next_r=current_r+dr[i], next_c=current_c+dc[i];

						if(next_r<0||N<=next_r||next_c<0||N<=next_c||visited[next_r][next_c]||!map[next_r][next_c])
							continue;

						map[next_r][next_c]=count;
						visited[next_r][next_c]=true;
						queue[rear++]=next_r<<7|next_c;
					}

					++front;
				}
			}

	for(int land=1;land<=count;++land)
	{
		int front=0, rear=0, distance=0;

		memset(visited,0,10000*sizeof(bool));

		for(int r=0;r<N;++r)
			for(int c=0;c<N;++c)
				if(!map[r][c])
				{
					bool adjacent=false;

					for(int i=0;i<4;++i)
					{
						int next_r=r+dr[i], next_c=c+dc[i];

						if(next_r<0||N<=next_r||next_c<0||N<=next_c||map[next_r][next_c]!=land)
							continue;

						adjacent=true;
					}

					if(adjacent)
					{
						visited[r][c]=true;
						queue[rear++]=r<<7|c;
					}
				}

		while(front<rear)
		{
			int previous_rear=rear;

			++distance;
			while(front<previous_rear)
			{
				int current_r=queue[front]>>7, current_c=queue[front]&127;

				for(int i=0;i<4;++i)
				{
					int next_r=current_r+dr[i], next_c=current_c+dc[i];

					if(next_r<0||N<=next_r||next_c<0||N<=next_c)
							continue;
					else if(!map[next_r][next_c]&&!visited[next_r][next_c])
					{
						visited[next_r][next_c]=true;
						queue[rear++]=next_r<<7|next_c;
					}
					else if(map[next_r][next_c]&&map[next_r][next_c]!=land)
					{
						front=rear;
						break;
					}
				}

				++front;
			}
		}

		min=distance<min?distance:min;
	}

	printf("%d", min);
	return 0;
}