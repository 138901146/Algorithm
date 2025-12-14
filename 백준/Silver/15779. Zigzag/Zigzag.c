#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, count=2, max=2;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	for(int i=2;i<N;++i)
		if(A[i-2]<=A[i-1]&&A[i-1]<=A[i]||A[i]<=A[i-1]&&A[i-1]<=A[i-2])
			count=2;
		else
		{
			++count;
			max=count<max?max:count;
		}

	printf("%d", max);
	return 0;
}