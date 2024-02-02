#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, pole, length=0, *LIS=NULL;

	scanf("%d", &N);
	LIS=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		int left=0, right=length, mid;
		LIS[i]=1000000000;

		scanf("%d", &pole);

		while(left<right)
		{
			mid=left+right>>1;

			if(LIS[mid]>pole)
				right=mid-1;
			else if(LIS[mid]<pole)
				left=mid+1;
			else
				break;
		}
		mid=left+right>>1;

		if(pole<=LIS[mid])
			LIS[mid]=pole;
		else
			LIS[mid+1]=pole;
		length+=mid==length;
	}

	printf("%d", N-length);
	free(LIS);
	return 0;
}