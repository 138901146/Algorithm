#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *count=NULL, max=0, max_index, *prev=NULL, *stack=NULL, index;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	count=(int *)malloc(N*sizeof(int));
	prev=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		prev[n]=n;
		count[n]=1;
		scanf("%d", &A[n]);

		for(int i=0;i<n;i++)
			if(A[i]<A[n] && count[n]<=count[i])
			{
				count[n]=count[i]+1;
				prev[n]=i;
			}

		if(count[n]>max)
		{
			max=count[n];
			max_index=n;
		}
	}

	stack=(int *)malloc(max*sizeof(int));
	index=max;
	while(index>0)
	{
		stack[--index]=A[max_index];
		max_index=prev[max_index];
	}

	printf("%d\n", max);
	for(int i=0;i<max;i++)
		printf("%d ", stack[i]);
	printf("\n");
	free(stack);
	free(prev);
	free(count);
	free(A);
	return 0;
}