#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int N, M, *A=NULL, target;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);
	qsort((void *)A,(size_t)N,sizeof(int),compare);

	scanf("%d", &M);

	while(M--)
	{
		scanf("%d", &target);

		int left=0, right=N-1, mid;
		bool found=false;

		while(left<=right)
		{
			mid=left+right>>1;

			if(A[mid]==target)
			{
				found=true;
				break;
			}
			else if(A[mid]<target)
				left=mid+1;
			else
				right=mid-1;
		}

		printf("%d\n", found);
	}

	free(A);
	return 0;
}