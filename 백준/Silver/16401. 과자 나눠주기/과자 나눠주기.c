#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *L=NULL, low=1, high=0, answer=0;

	scanf("%d%d", &M, &N);
	L=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d", &L[n]);
		high=high<L[n]?L[n]:high;
	}

	while(low<=high)
	{
		int mid=low+high>>1, count=0;

		for(int n=0;n<N;++n)
			count+=L[n]/mid;

		if(M<=count)
		{
			answer=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}

	printf("%d", answer);
	free(L);
	return 0;
}