#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, K, score[50];

	scanf("%d", &K);

	for(int X=1;X<=K;++X)
	{
		int gap=0;

		scanf("%d", &N);

		for(int i=0;i<N;++i)
			scanf("%d", &score[i]);
		qsort((void *)score,(size_t)N,sizeof(int),compare);

		for(int i=1;i<N;++i)
			gap=score[i]-score[i-1]>gap?score[i]-score[i-1]:gap;

		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", X, score[N-1], score[0], gap);
	}

	return 0;
}