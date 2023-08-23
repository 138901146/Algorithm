#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, *A=NULL, *LIS=NULL, max=0;

	scanf("%d", &n);
	A=(int *)malloc(n*sizeof(int));
	LIS=(int *)malloc(n*sizeof(int));

	for(int i=0;i<n;i++)
	{
		scanf("%d", &A[i]);

		LIS[i]=1;
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && LIS[i]<LIS[j]+1)
				LIS[i]=LIS[j]+1;

		max=LIS[i]>max?LIS[i]:max;
	}

	printf("%d\n", max);
	free(LIS);
	free(A);
	return 0;
}