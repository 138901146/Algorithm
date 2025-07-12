#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(float *)x<*(float *)y?-1:1;
}

int main(void)
{
	int N;
	float *score=NULL;

	scanf("%d", &N);
	score=(float *)malloc(N*sizeof(float));

	for(int n=0;n<N;++n)
		scanf("%f", &score[n]);
	qsort((void *)score,(size_t)N,sizeof(float),compare);

	for(int n=0;n<7;++n)
		printf("%.3f\n", score[n]);
	free(score);
	return 0;
}