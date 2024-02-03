#include<stdio.h>

int main(void)
{
	int n, port, length=0, LIS[40000];

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		int left=0, right=length, mid;
		LIS[i]=1000000000;

		scanf("%d", &port);

		while(left<right)
		{
			mid=left+right>>1;

			if(LIS[mid]>port)
				right=mid-1;
			else if(LIS[mid]<port)
				left=mid+1;
			else
				break;
		}
		right=right<0?0:right;
		mid=left+right>>1;

		if(port<=LIS[mid])
			LIS[mid]=port;
		else
			LIS[mid+1]=port;
		length+=mid==length;
	}

	printf("%d", length);
	return 0;
}