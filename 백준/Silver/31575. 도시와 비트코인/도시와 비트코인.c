#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, queue[90000]={0}, front=0, rear=1;
	bool map[300][300], visited[300][300]={false};

	scanf("%d%d", &N, &M);

	for(int m=0;m<M;++m)
		for(int n=0;n<N;++n)
			scanf("%d", &map[m][n]);

	visited[0][0]=true;

	while(front<rear && !visited[M-1][N-1])
	{
		int r=queue[front]>>9, c=queue[front]&511;

		if(r<M-1 && map[r+1][c] && !visited[r+1][c])
		{
			visited[r+1][c]=true;
			queue[rear++]=(r+1)<<9|c;
		}

		if(c<N-1 && map[r][c+1] && !visited[r][c+1])
		{
			visited[r][c+1]=true;
			queue[rear++]=r<<9|c+1;
		}

		++front;
	}

	printf("%s", visited[M-1][N-1]?"Yes":"No");
	return 0;
}