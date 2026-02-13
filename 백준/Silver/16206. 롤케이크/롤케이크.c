#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	if(*(int *)x%10==0&&*(int *)y%10==0)
		return *(int *)x<*(int *)y?-1:1;
	else if(*(int *)x%10==0)
		return -1;
	else if(*(int *)y%10==0)
		return 1;
	else
		return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, M, *A=NULL, count=0;

	scanf("%d%d", &N, &M);

	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	qsort((void *)A,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		if(A[i]<10)
			continue;
		else if(A[i]%10)
			if(M<=A[i]/10)
			{
				count+=M;
				M=0;
				break;
			}
			else
			{
				count+=A[i]/10;
				M-=A[i]/10;
			}
		else
			if(M<A[i]/10-1)
			{
				count+=M;
				break;
			}
			else
			{
				count+=A[i]/10;
				M-=A[i]/10-1;
			}

	printf("%d", count);
	free(A);
	return 0;
}