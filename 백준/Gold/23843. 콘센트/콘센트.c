#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, M, *t=NULL, *time=NULL, max=0;

	scanf("%d%d", &N, &M);
	t=(int *)malloc(N*sizeof(int));
	time=(int *)calloc(M,sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &t[i]);
	qsort((void *)t,(size_t)N,sizeof(int),compare);

	for(int i=N-1;i>=0;i--)
	{
		int min=0;
		for(int m=0;m<M;m++)
			min=time[min]>time[m]?m:min;
		time[min]+=t[i];
	}

	for(int m=0;m<M;m++)
		max=time[m]>max?time[m]:max;

	printf("%d\n", max);
	free(time);
	free(t);
	return 0;
}