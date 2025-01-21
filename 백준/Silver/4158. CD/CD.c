#include<stdio.h>

int sg[1000000], sy[1000000];

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	while(N || M)
	{
		int n=0, m=0, count=0;

		for(int i=0;i<N;++i)
			scanf("%d", &sg[i]);
		for(int i=0;i<M;++i)
			scanf("%d", &sy[i]);


		while(n<N && m<M)
			if(sg[n]<sy[m])
				++n;
			else if(sy[m]<sg[n])
				++m;
			else
			{
				++count;
				++n;
				++m;
			}

		printf("%d\n", count);
		scanf("%d%d", &N, &M);
	}

	return 0;
}