#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *pot=NULL;
	unsigned long long left=0, right=2147483648, mid, ans, count, sum=0;

	scanf("%d%d", &N, &K);
	pot=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &pot[n]);
		sum+=pot[n];
	}

	if(sum==0)
	{
		printf("0\n");
		free(pot);
		return 0;
	}

	while(left<=right)
	{
		count=0;
		mid=(left+right)>>1;

		for(int n=0;n<N;n++)
			count+=pot[n]/mid;

		if(count<K)
			right=mid-1;
		else
		{
			ans=mid;
			left=mid+1;
		}
	}

	printf("%lld\n", ans);
	free(pot);
	return 0;
}