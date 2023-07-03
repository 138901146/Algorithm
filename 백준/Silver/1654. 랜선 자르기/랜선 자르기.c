#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *lan=NULL;
	unsigned long long left=0, right=2147483648, mid, ans, count;

	scanf("%d%d", &N, &K);
	lan=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &lan[n]);

	while(left<=right)
	{
		count=0;
		mid=(left+right)>>1;

		for(int n=0;n<N;n++)
			count+=lan[n]/mid;

		if(count<K)
			right=mid-1;
		else
		{
			ans=mid;
			left=mid+1;
		}
	}

	printf("%lld\n", ans);
	free(lan);
	return 0;
}