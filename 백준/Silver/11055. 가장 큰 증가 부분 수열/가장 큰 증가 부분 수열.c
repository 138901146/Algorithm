#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *sum=NULL, max=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	sum=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &A[n]);
		sum[n]=A[n];

		for(int i=0;i<n;i++)
			if(A[i]<A[n] && sum[i]+A[n]>sum[n])
				sum[n]=sum[i]+A[n];
		max=sum[n]>max?sum[n]:max;
	}

	printf("%d\n", max);
	free(sum);
	free(A);
	return 0;
}