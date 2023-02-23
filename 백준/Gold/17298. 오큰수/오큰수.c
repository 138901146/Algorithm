#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *NGE=NULL, *stack=NULL, current=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	NGE=(int *)calloc(N,sizeof(int));
	stack=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &A[n]);

		while(current>0)
			if(A[stack[current-1]]<A[n])
				NGE[stack[--current]]=A[n];
			else
				break;

		stack[current++]=n;
	}

	for(int n=0;n<N;n++)
		printf("%d ", NGE[n]==0?-1:NGE[n]);
	printf("\n");
	free(NGE);
	free(stack);
	free(A);
	return 0;
}