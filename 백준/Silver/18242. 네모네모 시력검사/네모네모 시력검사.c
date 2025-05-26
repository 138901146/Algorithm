#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, left, up, l_size=0, u_size=0;
	char grid[100][101]={0};
	bool start=false;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		scanf("%s", grid[n]);

	for(int n=0;n<N&&!start;++n)
		for(int m=0;m<M&&!start;++m)
			if(grid[n][m]=='#')
			{
				up=n;
				left=m;
				start=true;
			}

	for(int i=left;i<M&&grid[up][i]=='#';++i,++l_size);
	for(int i=up;i<N&&grid[i][left]=='#';++i,++u_size);

	if(l_size!=u_size)
	{
		printf("%s", l_size<u_size?"UP":"LEFT");
		return 0;
	}
	for(int i=0;i<l_size;++i)
		if(grid[up+i][left+l_size-1]!='#')
		{
			printf("RIGHT");
			return 0;
		}

	printf("DOWN");
	return 0;
}