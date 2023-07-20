#include<stdio.h>

int main(void)
{
	int N, A[1001], max[1001]={0, }, best, length=0, previous[1001], backtrack[1001];

	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		max[i]=1;
		scanf("%d", &A[i]);
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && max[i]<max[j]+1)
			{
				max[i]=max[j]+1;
				previous[i]=j;
			}

		if(max[i]>length)
		{
			length=max[i];
			best=i;
		}
	}

	printf("%d\n", length);
	for(int i=0;i<length;i++)
	{
		backtrack[i]=A[best];
		best=previous[best];
	}
	for(int i=length-1;i>=0;i--)
		printf("%d ", backtrack[i]);
	printf("\n");
	return 0;
}