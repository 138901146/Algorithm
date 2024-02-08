#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *A=NULL, M, number;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);
	qsort((void *)A,(size_t)N,sizeof(int),compare);

	scanf("%d", &M);

	while(M--)
	{
		int left=0, right=N-1, mid;

		scanf("%d", &number);

		while(left<right)
		{
			mid=left+right>>1;

			if(A[mid]<number)
				left=mid+1;
			else if(number<A[mid])
				right=mid-1;
			else
				break;
		}
		right=right<0?0:right;
		mid=left+right>>1;

		printf("%d\n", A[mid]==number);
	}

	free(A);
	return 0;
}