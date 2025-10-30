#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, M, count=0;

		scanf("%d%d", &N, &M);

		while(N--)
		{
			char grid[101]={0};

			scanf("%s", grid);

			for(int m=0;m<M;++m)
				count+=grid[m]=='.';
		}

		printf("%s\n", count&1?"sewon":"pizza");
	}

	return 0;
}