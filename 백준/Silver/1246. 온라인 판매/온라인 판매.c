#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *P=NULL, smallest;

	scanf("%d%d", &N, &M);
	smallest=N>M?M-1:N-1;
	P=(int *)malloc(M*sizeof(int));

	for(int i=0;i<M;++i)
		scanf("%d", &P[i]);
	qsort((void *)P,(size_t)M,sizeof(int),compare);

	for(int i=smallest;i>=0;--i)
		smallest=(smallest+1)*P[smallest]<(i+1)*P[i]?i:smallest;

	printf("%d %d", P[smallest], (smallest+1)*P[smallest]);
	free(P);
	return 0;
}