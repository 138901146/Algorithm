#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, K, map[200][200], X, Y, S, queue[40000], front=0, rear=1, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	bool visited[200][200]={false};

	scanf("%d%d", &N, &K);

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			scanf("%d", &map[r][c]);
	scanf("%d%d%d", &S, &X, &Y);

	if(map[--X][--Y])
	{
		printf("%d", map[X][Y]);
		return 0;
	}
	visited[X][Y]=true;
	queue[0]=X<<8|Y;

	while(S--)
	{
		int min=1024, previous_rear=rear;

		while(front<previous_rear)
		{
			int r=queue[front]>>8, c=queue[front]&255;

			for(int i=0;i<4;++i)
			{
				int next_r=r+dr[i], next_c=c+dc[i];

				if(next_r<0 || N<=next_r || next_c<0 || N<=next_c || visited[next_r][next_c])
					continue;

				if(map[next_r][next_c])
					min=map[next_r][next_c]<min?map[next_r][next_c]:min;

				visited[next_r][next_c]=true;
				queue[rear++]=next_r<<8|next_c;
			}

			++front;
		}

		if(min!=1024)
		{
			printf("%d", min);
			return 0;
		}
	}

	printf("0");
	return 0;
}