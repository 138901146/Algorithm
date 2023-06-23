#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *A=NULL, count=0;

	scanf("%d%d", &N, &M);
	A=(int *)malloc((N+1)*sizeof(int));
	A[0]=0;

	for(int i=1;i<=N;i++)
	{
		scanf("%d", &A[i]);
		A[i]+=A[i-1];
	}

	for(int i=N;i>0&&A[i]>=M;i--)
	{
		int left=0, right=i-1, mid;

		while(left<right)
		{
			mid=(left+right)>>1;

			if(A[i]-A[mid]==M)
				break;
			else if(A[i]-A[mid]<M)
				right=mid-1;
			else
				left=mid+1;
		}

		mid=(left+right)>>1;
		count+=A[i]-A[mid]==M;
	}

	printf("%d\n", count);
	free(A);
	return 0;
}