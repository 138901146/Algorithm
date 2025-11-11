#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, num, left=1;
	long long *sum=NULL, k, count=0;

	scanf("%d", &n);
	sum=(long long *)calloc(n+1,sizeof(long long));

	for(int i=1;i<=n;++i)
	{
		scanf("%lld", &sum[i]);
		sum[i]+=sum[i-1];
	}

	scanf("%lld", &k);

	for(int right=1;right<=n;++right)
	{
		if(sum[right]<=k)
			continue;

		while(left<=right&&k<sum[right]-sum[left-1])
			++left;

		count+=left-1;
	}

	printf("%lld", count);
	free(sum);
	return 0;
}