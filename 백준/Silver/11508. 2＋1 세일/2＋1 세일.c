#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, *C=NULL, price=0;

	scanf("%d", &N);
	C=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &C[i]);
	qsort((void *)C,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		if(i%3!=2)
			price+=C[i];

	printf("%d", price);
	free(C);
	return 0;
}