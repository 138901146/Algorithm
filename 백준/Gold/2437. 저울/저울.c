#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *weight=NULL, sum=1;

	scanf("%d", &N);
	weight=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
		scanf("%d", &weight[n]);

	qsort((void *)weight,(size_t)N,sizeof(int),compare);

	for(int n=0;n<N;n++)
		if(sum>=weight[n])
			sum+=weight[n];
		else
			break;

	printf("%d\n", sum);
	free(weight);
	return 0;
}