#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int n, *x=NULL;
	long long sum=0, distance=0;

	scanf("%d", &n);
	x=(int *)malloc(n*sizeof(int));

	for(int i=0;i<n;++i)
		scanf("%d", &x[i]);
	qsort((void *)x,(size_t)n,sizeof(int),compare);

	sum=x[0];
	for(int i=1;i<n;++i)
	{
		distance+=(long long)i*x[i]-sum;
		sum+=x[i];
	}

	printf("%lld", distance<<1);
	free(x);
	return 0;
}