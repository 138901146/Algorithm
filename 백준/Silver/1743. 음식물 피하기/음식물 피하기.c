#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	short N, M, K, r, c, queue[10000], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, max=0;
	bool food_trash[101][101]={false}, visited[101][101]={false};

	scanf("%hd%hd%hd", &N, &M, &K);

	while(K--)
	{
		scanf("%hd%hd", &r, &c);
		food_trash[r][c]=true;
	}

	for(int n=1;n<=N;++n)
		for(int m=1;m<=M;++m)
			if(food_trash[n][m] && !visited[n][m])
			{
				int front=0, rear=1;

				queue[0]=n<<7|m;
				visited[n][m]=true;

				while(front<rear)
				{
					r=queue[front]>>7;
					c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						r+=dr[i];
						c+=dc[i];

						if(0<r && r<=N && 0<c && c<=M && food_trash[r][c] && !visited[r][c])
						{
							visited[r][c]=true;
							queue[rear++]=r<<7|c;
						}

						r-=dr[i];
						c-=dc[i];
					}

					++front;
				}

				max=rear<max?max:rear;
			}

	printf("%hd", max);
	return 0;
}