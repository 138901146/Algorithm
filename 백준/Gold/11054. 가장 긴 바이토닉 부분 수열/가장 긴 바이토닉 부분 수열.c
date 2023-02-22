#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *S=NULL, *E=NULL, max=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	S=(int *)calloc(N,sizeof(int));
	E=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);

	for(int n=0;n<N;n++)
	{
		S[n]=1;
		for(int i=0;i<n;i++)
			if(A[i]<A[n] && S[i]>=S[n])
				S[n]=S[i]+1;
	}
	for(int n=N-1;n>=0;n--)
	{
		E[n]=1;
		for(int i=N-1;i>n;i--)
			if(A[i]<A[n] && E[i]>=E[n])
				E[n]=E[i]+1;

		max=S[n]+E[n]-1>max?S[n]+E[n]-1:max;
	}

	printf("%d\n", max);
	free(A);
	free(S);
	free(E);
	return 0;
}