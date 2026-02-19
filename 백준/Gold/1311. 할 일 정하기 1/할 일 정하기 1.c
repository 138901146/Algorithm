#include<stdio.h>
#include<malloc.h>

#define INF 1000000

int N, **D=NULL, **min=NULL;

int simulate(int current,int done)
{
	if(current==N)
		return 0;
	else if(min[current][done]!=INF)
		return min[current][done];

	for(int i=0;i<N;++i)
		if(!(1<<i&done))
			min[current][done]=min[current][done]<simulate(current+1,1<<i|done)+D[current][i]?min[current][done]:simulate(current+1,1<<i|done)+D[current][i];

	return min[current][done];
}

int main(void)
{
	scanf("%d", &N);

	D=(int **)malloc(N*sizeof(int *));
	min=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;++i)
	{
		D[i]=(int *)malloc(N*sizeof(int));
		min[i]=(int *)malloc((1<<N)*sizeof(int));

		for(int j=0;j<N;++j)
			scanf("%d", &D[i][j]);
	}

	for(int i=0;i<N;++i)
		for(int j=0;j<1<<N;++j)
			min[i][j]=INF;

	printf("%d", simulate(0,0));
	for(int i=0;i<N;++i)
	{
		free(D[i]);
		free(min[i]);
	}
	free(D);
	free(min);
	return 0;
}