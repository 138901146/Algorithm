#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *budget=NULL, low=0, high=0, mid, answer=0;

	scanf("%d", &N);
	budget=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d", &budget[n]);
		high=budget[n]>high?budget[n]:high;
	}

	scanf("%d", &M);

	while(low<=high)
	{
		int sum=0;
		mid=low+high>>1;

		for(int n=0;n<N;++n)
			sum+=budget[n]<mid?budget[n]:mid;

		if(sum<=M)
		{
			answer=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}

	printf("%d", answer);
	free(budget);
	return 0;
}