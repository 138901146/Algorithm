#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	while(N || M)
	{
		int n=0, m=0, count=0, *sg=malloc(N*sizeof(int)), *sy=malloc(N*sizeof(int));

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
		free(sg);
		free(sy);

		scanf("%d%d", &N, &M);
	}

	return 0;
}