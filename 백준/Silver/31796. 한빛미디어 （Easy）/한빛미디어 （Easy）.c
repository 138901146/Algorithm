#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *S=NULL, count=0, min=0;

	scanf("%d", &N);
	S=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &S[i]);
	qsort((void *)S,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		if(min<<1<=S[i])
		{
			min=S[i];
			++count;
		}

	printf("%d", count);
	free(S);
	return 0;
}