#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *B=NULL, S=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	for(int i=0;i<N;i++)
		scanf("%d", &B[i]);

	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
		{
			if(A[i]>A[j])
			{
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
			if(B[i]<B[j])
			{
				int temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}
		}

	for(int i=0;i<N;i++)
		S+=A[i]*B[i];

	printf("%d\n", S);

	free(A);
	free(B);
	return 0;
}