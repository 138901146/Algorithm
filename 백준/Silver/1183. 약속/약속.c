#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, A, B, *appointment=NULL;

	scanf("%d", &N);

	if(N&1)
	{
		printf("1");
		return 0;
	}

	appointment=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &A, &B);
		appointment[i]=A-B;
	}
	qsort((void *)appointment,(size_t)N,sizeof(int),compare);

	printf("%d", appointment[N>>1]-appointment[(N>>1)-1]+1);
	free(appointment);
	return 0;
}