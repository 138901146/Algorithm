#include<stdio.h>
#include<malloc.h>

#define INF 12345678

int main(void)
{
	int N, *A, **result=NULL;

	scanf("%d", &N);
	A=(int *)calloc(N+1,sizeof(int));
	result=(int **)malloc((N+1)*sizeof(int *));

	result[0]=(int *)malloc(4*sizeof(int));
	result[0][0]=result[0][1]=result[0][2]=result[0][3]=-INF;
	for(int n=1;n<=N;++n)
	{
		scanf("%d", &A[n]);
		result[n]=(int *)malloc(4*sizeof(int));

		for(int i=0;i<4;++i)
			result[n][i]=result[n-1][i];

		result[n][0]=result[n][0]<-A[n]?-A[n]:result[n][0];
		if(1<n)
		{
			result[n][1]=result[n][1]<result[n-1][0]+A[n]?result[n-1][0]+A[n]:result[n][1];
			if(2<n)
			{
				result[n][2]=result[n][2]<result[n-1][1]-A[n]?result[n-1][1]-A[n]:result[n][2];
				if(3<n)
					result[n][3]=result[n][3]<result[n-1][2]+A[n]?result[n-1][2]+A[n]:result[n][3];
			}
		}
	}

	printf("%d", result[N][3]);
	for(int n=0;n<=N;++n)
		free(result[n]);
	free(result);
	free(A);
	return 0;
}