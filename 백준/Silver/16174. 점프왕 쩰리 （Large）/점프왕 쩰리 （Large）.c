#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, map[64][64], queue[4096]={0}, front=0, rear=1;
	bool visited[64][64]={true,false,};

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &map[i][j]);

	while(front<rear&&!visited[N-1][N-1])
	{
		int r=queue[front]>>8, c=queue[front]&63;

		if(r+map[r][c]<N&&!visited[r+map[r][c]][c])
		{
			visited[r+map[r][c]][c]=true;
			queue[rear++]=r+map[r][c]<<8|c;
		}
		if(c+map[r][c]<N&&!visited[r][c+map[r][c]])
		{
			visited[r][c+map[r][c]]=true;
			queue[rear++]=r<<8|c+map[r][c];
		}

		++front;
	}

	printf("%s", visited[N-1][N-1]?"HaruHaru":"Hing");
	return 0;
}