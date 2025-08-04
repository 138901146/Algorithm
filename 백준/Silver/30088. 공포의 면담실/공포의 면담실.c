#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, count, counsel, *total=NULL;
	long long answer=0;

	scanf("%d", &N);
	total=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d", &count);

		while(count--)
		{
			scanf("%d", &counsel);
			total[n]+=counsel;
		}
	}
	qsort((void *)total,(size_t)N,sizeof(int),compare);

	for(int n=0;n<N;++n)
		answer+=(n+1)*total[n];

	printf("%lld", answer);
	free(total);
	return 0;
}