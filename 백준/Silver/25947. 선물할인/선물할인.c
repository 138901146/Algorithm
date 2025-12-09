#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int n, a, b, *price=NULL, max=0;
	long long *sum=NULL;

	scanf("%d%d%d", &n, &b, &a);
	price=(int *)malloc(n*sizeof(int));

	for(int i=0;i<n;++i)
		scanf("%d", &price[i]);
	qsort((void *)price,(size_t)n,sizeof(int),compare);

	sum=(long long *)calloc(n+1,sizeof(long long));
	for(int i=0;i<n;++i)
		sum[i+1]=sum[i]+price[i];

	for(int i=1;i<=n;++i)
		if(sum[i]+sum[i-(i<=a?i:a)]>>1<=b)
			max=i;
		else
			break;

	printf("%d", max);
	free(price);
	free(sum);
	return 0;
}