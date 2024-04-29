#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x<*(long long *)y?-1:1;
}

int main(void)
{
	int n;
	long long *x=NULL, sum=0, distance=0;

	scanf("%d", &n);
	x=(long long *)malloc(n*sizeof(long long));

	for(int i=0;i<n;++i)
		scanf("%lld", &x[i]);
	qsort((void *)x,(size_t)n,sizeof(long long),compare);

	sum=x[0];
	for(int i=1;i<n;++i)
	{
		distance+=i*x[i]-sum;
		sum+=x[i];
	}

	printf("%lld", distance<<1);
	free(x);
	return 0;
}