#include<stdio.h>

int main(void)
{
	int N, M, arr[5000], left=0, right=10000, fit=10000;

	scanf("%d%d", &N, &M);
	for(int n=0;n<N;++n)
		scanf("%d", &arr[n]);

	while(left<=right)
	{
		int count=1, last=0, mid=left+right>>1;

		while(last<N)
		{
			int max=arr[last], min=arr[last];

			while(last<N&&max-min<=mid)
			{
				max=arr[last]<max?max:arr[last];
				min=arr[last]<min?arr[last]:min;
				++last;

				if(mid<max-min)
				{
					++count;
					--last;
				}
			}
		}

		if(count<=M)
		{
			fit=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", fit);
	return 0;
}