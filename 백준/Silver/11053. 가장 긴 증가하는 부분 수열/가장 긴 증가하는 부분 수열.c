#include<stdio.h>

int main(void)
{
	int N, A[1001], max[1001]={0, }, best=0;

	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		max[i]=1;
		scanf("%d", &A[i]);
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && max[i]<max[j]+1)
				max[i]=max[j]+1;
		best=max[i]>best?max[i]:best;
	}

	printf("%d\n", best);
	return 0;
}