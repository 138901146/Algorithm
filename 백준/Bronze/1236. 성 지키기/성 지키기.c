#include<stdio.h>

int main(void)
{
	int N, M, n=0, m=0;
	char castle[50][51]={0};

	scanf("%d%d", &N, &M);

	for(int r=0;r<N;++r)
		scanf("%s", castle[r]);

	for(int r=0;r<N;++r)
	{
		int guard=0;

		for(int c=0;c<M;++c)
			if(castle[r][c]=='X')
			{
				guard=1;
				break;
			}

		if(!guard)
			++n;
	}

	for(int c=0;c<M;++c)
	{
		int guard=0;

		for(int r=0;r<N;++r)
			if(castle[r][c]=='X')
			{
				guard=1;
				break;
			}

		if(!guard)
			++m;
	}

	printf("%d", n<m?m:n);
	return 0;
}