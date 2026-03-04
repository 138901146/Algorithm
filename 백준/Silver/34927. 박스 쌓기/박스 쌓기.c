#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *w=NULL, count=1;
	long long total;

	scanf("%d", &N);

	w=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &w[i]);

	qsort((void *)w,(size_t)N,sizeof(int),compare);

	total=w[0];
	for(int i=1;i<N;++i)
		if(total<=(long long)w[i])
		{
			++count;
			total+=w[i];
		}

	printf("%d", count);
	free(w);
	return 0;
}