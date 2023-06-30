#include<stdio.h>

int main(void)
{
	long long N, k, left=1, right, mid, count, ans;

	scanf("%lld", &N);
	right=N*N;
	scanf("%lld", &k);

	while(left<=right)
	{
		count=0;
		mid=(left+right)>>1;

		for(int i=1;i<=N;i++)
			count+=N<mid/i?N:mid/i;

		if(count<k)
			left=mid+1;
		else
		{
			ans=mid;
			right=mid-1;
		}
	}

	printf("%lld\n", ans);
	return 0;
}