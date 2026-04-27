#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int id, score;
}
test;

int compare(const void *x,const void *y)
{
	return ((test *)x)->score<((test *)y)->score?1:-1;
}

int main(void)
{
	int N, K, count=0;
	test **data=NULL;
	bool *captain=NULL;

	scanf("%d%d", &N, &K);

	if(N==1)
	{
		printf("1");
		return 0;
	}

	captain=(bool *)calloc(N,sizeof(bool));
	data=(test **)malloc(K*sizeof(test *));
	for(int k=0;k<K;++k)
		data[k]=(test *)malloc(N*sizeof(test));

	for(int n=0;n<N;++n)
		for(int k=0;k<K;++k)
		{
			scanf("%d", &data[k][n].score);
			data[k][n].id=n;
		}

	for(int k=0;k<K;++k)
	{
		qsort((void *)data[k],(size_t)N,sizeof(test),compare);

		if(data[k][1].score<data[k][0].score)
			captain[data[k][0].id]=true;

		free(data[k]);
	}
	free(data);

	for(int n=0;n<N;++n)
		count+=captain[n];

	printf("%d", count);
	free(captain);
	return 0;
}