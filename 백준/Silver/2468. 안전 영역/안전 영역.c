#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, max_height=1, area[100][100], max_count=1, queue[10000], move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &area[i][j]);
			max_height=area[i][j]>max_height?area[i][j]:max_height;
		}

	for(int n=max_height-1;n;--n)
	{
		int front=0, rear=0, count=0;
		bool visited[100][100]={false};

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				if(n<area[i][j] && !visited[i][j])
				{
					visited[i][j]=true;
					queue[rear++]=i<<7|j;
					++count;

					while(front<rear)
					{
						int r=queue[front]>>7, c=queue[front]&127;

						for(int k=0;k<4;++k)
						{
							r+=move[k][0];
							c+=move[k][1];

							if(0<=r && r<N && 0<=c && c<N && n<area[r][c] && !visited[r][c])
							{
								visited[r][c]=true;
								queue[rear++]=r<<7|c;
							}

							r-=move[k][0];
							c-=move[k][1];
						}

						++front;
					}
				}

		max_count=max_count<count?count:max_count;
	}

	printf("%d", max_count);
	return 0;
}