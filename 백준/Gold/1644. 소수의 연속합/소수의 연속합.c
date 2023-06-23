#include<stdio.h>
#include<stdbool.h>

long long sum[300000];

bool is_prime(int n)
{
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true;
}

int main(void)
{
	int size=1, count=0;
	long long N;

	scanf("%lld", &N);

	sum[0]=0;
	sum[1]=2;
	for(int i=3;i<=N;i+=2)
		if(is_prime(i))
		{
			sum[size+1]=sum[size]+i;
			size++;
		}

	for(int i=size;i>0 && sum[i]>=N;i--)
	{
		int left=0, right=i, mid;

		while(left<=right)
		{
			mid=(left+right)>>1;

			if(sum[i]-sum[mid]==N)
				break;
			else if(sum[i]-sum[mid]<N)
				right=mid-1;
			else
				left=mid+1;
		}

		if(left<=right)
		{
			mid=(left+right)>>1;
			count+=sum[i]-sum[mid]==N;
		}
	}

	printf("%d\n", count);
	return 0;
}