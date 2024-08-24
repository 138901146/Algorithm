#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int length=0, N, A, *LIS=NULL;

	scanf("%d", &N);
	LIS=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		int left=0, right=length, mid;
		LIS[i]=10000000;
		scanf("%d", &A);

		while(left<right)
		{
			mid=left+right>>1;
			if(LIS[mid]>A)
				right=mid-1;
			else if(LIS[mid]<A)
				left=mid+1;
			else
				break;
		}
		mid=left+right>>1;

		if(A<=LIS[mid])
			LIS[mid]=A;
		else
			LIS[mid+1]=A;
		length+=mid==length;
	}

	printf("%d", length);
	free(LIS);
	return 0;
}