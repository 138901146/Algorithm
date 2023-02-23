#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, B, C;
	long long int count=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	scanf("%d %d", &B, &C);

	for(int i=0;i<N;i++)
		if(A[i]<=B)
			count++;
		else if((A[i]-B)%C==0)
			count+=(A[i]-B)/C+1;
		else
			count+=(A[i]-B)/C+2;

	printf("%lld\n", count);

	free(A);
	return 0;
}