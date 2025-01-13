#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, *stack=NULL, top=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	stack=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	stack[0]=N-1;
	for(int i=N-2;0<=i;--i)
		if(A[i]==A[stack[top]])
			stack[top]=i;
		else
			stack[++top]=i;

	for(int i=0;i<N;++i)
	{
		while(0<=top && stack[top]<=i)
			--top;

		printf("%d ", top<0?-1:stack[top]+1);
	}

	free(A);
	free(stack);
	return 0;
}