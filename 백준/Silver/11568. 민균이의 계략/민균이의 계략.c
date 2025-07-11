#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int length=0, N, card, *LIS=NULL;

	scanf("%d", &N);
	LIS=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		int left=0, right=length, mid;
		LIS[i]=1000000000;
		scanf("%d", &card);

		while(left<right)
		{
			mid=left+right>>1;
			if(LIS[mid]>card)
				right=mid-1;
			else if(LIS[mid]<card)
				left=mid+1;
			else
				break;
		}
		mid=left+right>>1;

		if(card<=LIS[mid])
			LIS[mid]=card;
		else
			LIS[mid+1]=card;
		length+=mid==length;
	}

	printf("%d", length);
	free(LIS);
	return 0;
}