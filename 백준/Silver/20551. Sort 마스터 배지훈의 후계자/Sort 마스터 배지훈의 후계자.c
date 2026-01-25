#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *A=NULL, *D=NULL, *answer=NULL;

	scanf("%d%d", &N, &M);
	A=(int *)malloc(N*sizeof(int));
	D=(int *)malloc(M*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	for(int i=0;i<M;++i)
		scanf("%d", &D[i]);

	qsort((void *)A,(size_t)N,sizeof(int),compare);
	answer=(int *)malloc(M*sizeof(int));

	for(int i=0;i<M;++i)
	{
		int left=0, right=N-1, index=0;

		while(left<=right)
		{
			int mid=left+right>>1;

			if(A[mid]<D[i])
				left=mid+1;
			else
			{
				right=mid-1;
				index=mid;
			}
		}

		answer[i]=A[index]==D[i]?index:-1;
	}

	for(int i=0;i<M;++i)
		printf("%d\n", answer[i]);
	free(A);
	free(D);
	free(answer);
	return 0;
}