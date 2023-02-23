#include<stdio.h>
#include<stdlib.h>

int maximum_subarray(int *arr,int size)
{
	int sum=0, max=arr[0];

	for(int i=0;i<size;i++)
	{
		sum=arr[i]+sum>arr[i]?arr[i]+sum:arr[i];
		max=max>sum?max:sum;
	}

	return max;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, *X=NULL;

		scanf("%d", &N);
		X=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;n++)
			scanf("%d", &X[n]);

		printf("%d\n", maximum_subarray(X,N));
		free(X);
	}

	return 0;
}