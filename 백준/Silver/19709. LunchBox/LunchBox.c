#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, m, *k=NULL, count=0;

	scanf("%d%d", &N, &m);

	k=(int *)malloc(m*sizeof(int));
	for(int i=0;i<m;++i)
		scanf("%d", &k[i]);
	qsort((void *)k,(size_t)m,sizeof(int),compare);

	for(int i=0;i<m;++i)
		if(k[i]<=N)
		{
			++count;
			N-=k[i];
		}
		else
			break;

	printf("%d", count);
	free(k);
	return 0;
}