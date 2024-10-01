#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, *c=NULL, price;
	long long total=0, max=0;

	scanf("%d", &N);
	c=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &c[i]);
	qsort((void *)c,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		if(max<=(long long)c[i]*(i+1))
		{
			max=(long long)c[i]*(i+1);
			price=c[i];
		}

	printf("%lld %d", max, price);
	free(c);
	return 0;
}