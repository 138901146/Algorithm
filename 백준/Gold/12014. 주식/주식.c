#include<stdio.h>

int main(void)
{
	int T, N, K, price, LIS[10000];

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		int max=0;

		scanf("%d%d", &N, &K);

		for(int i=0;i<N;++i)
		{
			int left=0, right=max, mid;
			LIS[i]=10001;

			scanf("%d", &price);

			while(left<right)
			{
				mid=left+right>>1;

				if(LIS[mid]>price)
					right=mid-1;
				else if(LIS[mid]<price)
					left=mid+1;
				else
					break;
			}
			right=right<0?0:right;
			mid=left+right>>1;

			if(price<=LIS[mid])
				LIS[mid]=price;
			else
				LIS[mid+1]=price;
			max+=mid==max;
		}

		printf("Case #%d\n%d\n", t, K<=max);
	}

	return 0;
}