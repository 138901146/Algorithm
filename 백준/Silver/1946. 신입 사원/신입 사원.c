#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int paper, interview;
}
recruit;

int compare(const void *x,const void *y)
{
//	return ((recruit *)x)->paper<((recruit *)y)->paper?1:((recruit *)y)->paper<((recruit *)x)->paper?-1:((recruit *)x)->interview<((recruit *)y)->interview?-1:1;
	return ((recruit *)x)->paper<((recruit *)y)->paper?-1:1;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, count=0, max=123456;
		recruit *score=NULL;

		scanf("%d", &N);

		score=(recruit *)malloc(N*sizeof(recruit));

		for(int i=0;i<N;++i)
			scanf("%d%d", &score[i].paper, &score[i].interview);

		qsort((void *)score,(size_t)N,sizeof(recruit),compare);

		for(int i=0;i<N;++i)
			if(score[i].interview<max)
			{
				max=score[i].interview;
				++count;
			}

		printf("%d\n", count);
		free(score);
	}

	return 0;
}