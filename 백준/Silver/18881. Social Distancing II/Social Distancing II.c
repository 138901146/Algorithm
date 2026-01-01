#include<stdio.h>
#include<stdlib.h>

#define INF 1234567

typedef struct
{
	int x, sick;
}
cow;

int compare(const void *a,const void *b)
{
	return ((cow *)a)->x<((cow *)b)->x?-1:1;
}

int main(void)
{
	int N, R=INF, count=0, sick=0;
	cow *disease=NULL;

	scanf("%d", &N);
	disease=(cow *)malloc(N*sizeof(cow));

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &disease[i].x, &disease[i].sick);
		sick+=disease[i].sick;
	}
	qsort((void *)disease,(size_t)N,sizeof(cow),compare);

	for(int i=1;i<N;++i)
		if(disease[i-1].sick!=disease[i].sick)
			R=disease[i].x-disease[i-1].x<R?disease[i].x-disease[i-1].x:R;

	if(R==INF)
	{
		printf("%d", sick?1:0);
		free(disease);
		return 0;
	}

	count=disease[0].sick;
	for(int i=1;i<N;++i)
		if(disease[i-1].sick&&disease[i].sick&&R<=disease[i].x-disease[i-1].x)
			++count;
		else if(disease[i].sick&&!disease[i-1].sick)
			++count;

	printf("%d", count);
	free(disease);
	return 0;
}