#include<stdio.h>
#include<stdbool.h>

int N, M, K[5][5], max=0, dr[4][2]={{-1,0},{0,1},{1,0},{0,-1}}, dc[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool used[5][5]={false};

void check_max(int r,int c,int count)
{
	if(r==N)
	{
		max=count<max?max:count;
		return;
	}

	if(!used[r][c])
	{
		for(int i=0;i<4;++i)
		{
			bool proceedable=true;

			for(int j=0;j<2;++j)
				if(r+dr[i][j]<0||N<=r+dr[i][j]||c+dc[i][j]<0||M<=c+dc[i][j]||used[r+dr[i][j]][c+dc[i][j]])
				{
					proceedable=false;
					break;
				}

			if(proceedable)
			{
				used[r][c]=true;
				for(int j=0;j<2;++j)
				{
					used[r+dr[i][j]][c+dc[i][j]]=true;
					count+=K[r+dr[i][j]][c+dc[i][j]];
				}
				count+=K[r][c]<<1;

				if(c==M-1)
					check_max(r+1,0,count);
				else
					check_max(r,c+1,count);

				used[r][c]=false;
				count-=K[r][c]<<1;
				for(int j=0;j<2;++j)
				{
					used[r+dr[i][j]][c+dc[i][j]]=false;
					count-=K[r+dr[i][j]][c+dc[i][j]];
				}
			}
		}
	}

	if(c==M-1)
		check_max(r+1,0,count);
	else
		check_max(r,c+1,count);
}

int main(void)
{
	scanf("%d%d", &N, &M);

	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &K[i][j]);

	check_max(0,0,0);

	printf("%d", max);
	return 0;
}