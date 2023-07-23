#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, *ascending=NULL, *descending=NULL, max=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	ascending=(int *)malloc(N*sizeof(int));
	descending=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &A[i]);

		ascending[i]=1;
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && ascending[i]<ascending[j]+1)
				ascending[i]=ascending[j]+1;
	}
	for(int i=N-1;i>=0;i--)
	{
		descending[i]=1;
		for(int j=N-1;j>i;j--)
			if(A[j]<A[i] && descending[i]<descending[j]+1)
				descending[i]=descending[i]+1;

		max=ascending[i]+descending[i]>max?ascending[i]+descending[i]:max;
	}

	printf("%d\n", max-1);
	free(A);
	free(ascending);
	free(descending);
	return 0;
}