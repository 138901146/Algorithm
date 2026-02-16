#include<stdio.h>

int grid[5][5], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, result=0;

void simulate(int r,int c,int apple,int move)
{
	if(3<move||1<apple||result)
	{
		result=1<apple?1:result;
		return;
	}

	for(int i=0;i<4;++i)
	{
		int next_r=r+dr[i], next_c=c+dc[i], current_grid=grid[r][c], apple_parameter=apple+grid[r][c];

		if(1<apple_parameter)
		{
			result=1;
			return;
		}

		if(next_r<0||4<next_r||next_c<0||4<next_c||grid[next_r][next_c]==-1)
			continue;

		grid[r][c]=-1;
		simulate(next_r,next_c,apple_parameter,move+1);
		grid[r][c]=current_grid;
	}
}

int main(void)
{
	int r, c;

	for(r=0;r<5;++r)
		for(c=0;c<5;++c)
			scanf("%d", &grid[r][c]);

	scanf("%d%d", &r, &c);

	simulate(r,c,0,0);

	printf("%d", result);
	return 0;
}