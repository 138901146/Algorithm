#include<stdio.h>
#include<stdbool.h>

int A[3000][3000], queue[9000000];
bool visited[3000][3000]={false};

int main(void)
{
	int n, m, front=0, rear=1, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}}, distance=1;

	scanf("%d%d", &n, &m);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			scanf("%1d", &A[i][j]);
			if(A[i][j]==2)
			{
				A[i][j]=0;
				visited[i][j]=true;
				queue[0]=i<<12|j;
			}
		}

	while(front<rear)
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			int r=queue[front]>>12, c=queue[front]&4095;

			for(int i=0;i<4;++i)
			{
				r+=move[i][0];
				c+=move[i][1];

				if(r>=0 && r<n && c>=0 && c<m && A[r][c]!=1 && !visited[r][c])
				{
					if(A[r][c]>2)
					{
						printf("TAK\n%d", distance);
						return 0;
					}
					visited[r][c]=true;
					queue[rear++]=r<<12|c;
				}

				r-=move[i][0];
				c-=move[i][1];
			}

			++front;
		}
		++distance;
	}

	printf("NIE");
	return 0;
}