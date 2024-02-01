#include<stdio.h>
#include<stdbool.h>

int n, m, queue[250000], area=0, count=0, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
bool picture[500][500], visited[500][500]={false};

int main(void)
{
	scanf("%d%d", &n, &m);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d", &picture[i][j]);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(picture[i][j] && !visited[i][j])
			{
				int front=0, rear=1;
				queue[0]=i<<9|j;
				visited[i][j]=true;

				while(front<rear)
				{
					int r=queue[front]>>9, c=queue[front]&511;

					for(int k=0;k<4;++k)
					{
						r+=move[k][0];
						c+=move[k][1];

						if(r>=0 && r<n && c>=0 && c<m && picture[r][c] && !visited[r][c])
						{
							visited[r][c]=true;
							queue[rear++]=r<<9|c;
						}

						r-=move[k][0];
						c-=move[k][1];
					}

					++front;
				}

				area=rear>area?rear:area;
				++count;
			}

	printf("%d\n%d", count, area);
	return 0;
}