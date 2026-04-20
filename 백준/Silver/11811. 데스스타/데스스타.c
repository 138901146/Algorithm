#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *a=NULL, m;

	scanf("%d", &N);

	a=(int *)calloc(N,sizeof(int));

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &m);
			a[i]|=m;
			a[j]|=m;
		}

	for(int i=0;i<N;++i)
		printf("%d ", a[i]);

	free(a);
	return 0;
}