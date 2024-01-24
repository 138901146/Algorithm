#include<stdio.h>

int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int t, n, arr[100];

	scanf("%d", &t);

	while(t--)
	{
		long long sum=0;

		scanf("%d", &n);

		for(int i=0;i<n;++i)
		{
			scanf("%d", &arr[i]);

			for(int j=0;j<i;++j)
				sum+=gcd(arr[i],arr[j]);
		}

		printf("%lld\n", sum);
	}

	return 0;
}