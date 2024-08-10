#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, A, B, t[50];

	scanf("%d", &N);

	if(N&1)
	{
		printf("1");
		return 0;
	}

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &A, &B);
		t[i]=A-B;
	}
	qsort((void *)t,(size_t)N,sizeof(int),compare);

	printf("%d", t[N>>1]-t[N-1>>1]+1);
	return 0;
}