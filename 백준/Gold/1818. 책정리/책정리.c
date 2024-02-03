#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, book, length=0, *LIS=NULL;

	scanf("%d", &N);
	LIS=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		int left=0, right=length, mid;
		LIS[i]=1000000000;

		scanf("%d", &book);

		while(left<right)
		{
			mid=left+right>>1;

			if(LIS[mid]>book)
				right=mid-1;
			else if(LIS[mid]<book)
				left=mid+1;
			else
				break;
		}
		right=right<0?0:right;
		mid=left+right>>1;

		if(book<=LIS[mid])
			LIS[mid]=book;
		else
			LIS[mid+1]=book;
		length+=mid==length;
	}

	printf("%d", N-length);
	free(LIS);
	return 0;
}