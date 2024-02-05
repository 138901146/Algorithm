#include<stdio.h>

int N, price, LIS[100000];

int main(void)
{
	while(scanf("%d", &N)!=EOF)
	{
		int max=0;

		for(int i=0;i<N;++i)
		{
			int left=0, right=max, mid;
			LIS[i]=100001;

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

		printf("%d\n", max);
	}

	return 0;
}