#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, *B=NULL;
	bool *exist=NULL;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int)<<1);
	exist=(bool *)calloc(N+1,sizeof(bool));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	for(int i=0;i<N<<1;++i)
		scanf("%d", &B[i]);

	for(int i=0;i<N;++i)
	{
		exist[A[i]]=true;
		if(A[i]!=B[i])
		{
			printf("NO");
			free(A);
			free(B);
			free(exist);
			return 0;
		}
	}

	for(int i=N;i<N<<1;++i)
		if(!exist[B[i]])
		{
			printf("NO");
			free(A);
			free(B);
			free(exist);
			return 0;
		}

	printf("YES");
	free(A);
	free(B);
	free(exist);
	return 0;
}