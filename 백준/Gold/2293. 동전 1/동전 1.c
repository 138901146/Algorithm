#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int n, k, *coin=NULL, *count=NULL;

	scanf("%d%d", &n, &k);
	coin=(int *)malloc(n*sizeof(int));
	count=(int *)calloc(k+1,sizeof(int));

	for(int i=0;i<n;++i)
		scanf("%d", &coin[i]);
	qsort((void *)coin,(size_t)n,sizeof(int),compare);

	count[0]=1;
	for(int i=0;i<n;++i)
		for(int j=coin[i];j<=k;++j)
			count[j]+=count[j-coin[i]];

	printf("%d", count[k]);
	free(count);
	free(coin);
	return 0;
}