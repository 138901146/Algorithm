#include<stdio.h>

int main(void)
{
	int T, N, k, LIS[40000];

	scanf("%d", &T);

	while(T--)
	{
		int max=0;

		scanf("%d", &N);

		for(int i=0;i<N;++i)
		{
			int left=0, right=max, mid;
			LIS[i]=40001;

			scanf("%d", &k);

			while(left<right)
			{
				mid=left+right>>1;

				if(LIS[mid]>k)
					right=mid-1;
				else if(LIS[mid]<k)
					left=mid+1;
				else
					break;
			}
			right=right<0?0:right;
			mid=left+right>>1;

			if(k<=LIS[mid])
				LIS[mid]=k;
			else
				LIS[mid+1]=k;
			max+=mid==max;
		}

		printf("%d\n", max);
	}

	return 0;
}