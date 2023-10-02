#include<stdio.h>
#include<malloc.h>
#include<math.h>

int N, full;
double **W=NULL, **distance=NULL;

double tsp(int visited,int city)
{
	if(visited==full-1)
		return W[city][0]==0?10000000:W[city][0];
	else if(distance[city][visited]!=-1)
		return distance[city][visited];

	distance[city][visited]=10000000;
	for(int n=0;n<N;++n)
		if(!(visited&(1<<n)) && W[city][n]!=0)
		{
			double next=tsp(visited|(1<<n),n)+W[city][n];
			distance[city][visited]=distance[city][visited]<next?distance[city][visited]:next;
		}

	return distance[city][visited];
}

int main(void)
{
	int *x=NULL, *y=NULL;

	scanf("%d", &N);
	x=(int *)malloc(N*sizeof(int));
	y=(int *)malloc(N*sizeof(int));
	W=(double **)malloc(N*sizeof(double *));
	distance=(double **)malloc(N*sizeof(double *));
	full=1<<N;

	for(int i=0;i<N;++i)
	{
		W[i]=(double *)malloc(N*sizeof(double));
		distance[i]=(double *)malloc(full*sizeof(double));
	}

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &x[i], &y[i]);

		for(int j=0;j<=i;++j)
			W[i][j]=W[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		for(int j=0;j<full;++j)
			distance[i][j]=-1.0l;
	}

	printf("%lf", tsp(1,0));
	for(int n=0;n<N;++n)
	{
		free(W[n]);
		free(distance[n]);
	}
	free(W);
	free(distance);
	free(x);
	free(y);
	return 0;
}