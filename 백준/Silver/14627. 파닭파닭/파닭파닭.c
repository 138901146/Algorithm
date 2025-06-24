#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int S, *L=NULL;
	long long C, left=1, right=1000000000, max=0, total=0;

	scanf("%d%lld", &S, &C);
	L=(int *)malloc(S*sizeof(int));

	for(int s=0;s<S;++s)
	{
		scanf("%d", &L[s]);
		total+=L[s];
	}

	while(left<=right)
	{
		long long mid=left+right>>1, sum=0;

		for(int s=0;s<S;++s)
			sum+=L[s]/mid;

		if(sum<C)
			right=mid-1;
		else
		{
			max=mid;
			left=mid+1;
		}
	}

	printf("%lld", total-max*C);
	free(L);
	return 0;
}