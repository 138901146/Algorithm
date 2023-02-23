#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *x=NULL, *y=NULL, *rank=NULL;

	scanf("%d", &N);
	x=(int *)calloc(N,sizeof(int));
	y=(int *)calloc(N,sizeof(int));
	rank=(int *)calloc(N,sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		rank[i]++;
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			rank[i]+=x[j]>x[i]&&y[j]>y[i];

	for(int i=0;i<N;i++)
		printf("%d ", rank[i]);
	printf("\n");

	free(x);
	free(y);
	free(rank);
	return 0;
}