#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, a, b;
	bool reachable[101][101]={false};

	scanf("%d", &N);

	for(int n=1;n<N;++n)
	{
		scanf("%d%d", &a, &b);
		reachable[a][b]=true;
		reachable[n][n]=true;
	}
	reachable[N][N]=true;

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				reachable[start][end]|=reachable[start][mid]&&reachable[mid][end];

	for(int n=1;n<=N;++n)
	{
		bool final=true;

		for(int i=1;i<=N;++i)
			if(!reachable[i][n])
			{
				final=false;
				break;
			}

		if(final)
		{
			printf("%d", n);
			return 0;
		}
	}

	printf("-1");
	return 0;
}