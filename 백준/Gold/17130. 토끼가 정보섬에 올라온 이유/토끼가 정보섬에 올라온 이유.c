#include<stdio.h>
#include<stdbool.h>

char grid[1000][1001]={'\0'};
bool reachable[1000][2]={false};

int main(void)
{
	int N, M, start, up, down, carrot[1000][2]={0}, current=0, next=1, max=-1;

	scanf("%d%d", &N, &M);

	for(int r=0;r<N;++r)
	{
		getchar();
		scanf("%s", grid[r]);

		for(int c=0;c<M;++c)
			if(grid[r][c]=='R')
			{
				start=c;
				up=down=r;
			}
	}

	reachable[up][0]=true;
	for(int c=start;c<M-1;++c, current^=1, next^=1)
	{
		for(int r=down;r<=up;++r)
		{
			reachable[r][next]=false;
			carrot[r][next]=0;
		}

		for(int r=down;r<=up;++r)
		{
			if(!reachable[r][current])
				continue;

			for(int i=-1;i<2;++i)
				if(r+i>=0 && r+i<N)
					switch(grid[r+i][c+1])
					{
						case '.':
							reachable[r+i][next]=true;
							carrot[r+i][next]=carrot[r][current]>carrot[r+i][next]?carrot[r][current]:carrot[r+i][next];
							break;
						case '#':
							reachable[r+i][next]=false;
							carrot[r+i][next]=0;
							break;
						case 'C':
							reachable[r+i][next]=true;
							carrot[r+i][next]=carrot[r][current]+1>carrot[r+i][next]?carrot[r][current]+1:carrot[r+i][next];
							break;
						case 'O':
							reachable[r+i][next]=true;
							carrot[r+i][next]=carrot[r][current]>carrot[r+i][next]?carrot[r][current]:carrot[r+i][next];
							max=carrot[r+i][next]>max?carrot[r+i][next]:max;
							break;
					}
		}

		if(down>0 && reachable[down][current])
			--down;
		if(up<N-1 && reachable[up][current])
			++up;
	}

	printf("%d", max);
	return 0;
}