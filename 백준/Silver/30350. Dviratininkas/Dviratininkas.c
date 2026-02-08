#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int km, v;
}
rain;

int compare(const void *x,const void *y)
{
	return ((rain *)x)->v<((rain *)y)->v?1:-1;
}

int main(void)
{
	int N, K;
	rain *data=NULL;

	scanf("%d%d", &N, &K);

	data=(rain *)malloc(N*sizeof(rain));

	for(int i=0;i<N;++i)
	{
		scanf("%d", &data[i].v);
		data[i].km=i+1;
	}

	qsort((void *)data,(size_t)N,sizeof(rain),compare);

	for(int i=0;i<K;++i)
		printf("%d\n", data[i].km);
	free(data);
	return 0;
}