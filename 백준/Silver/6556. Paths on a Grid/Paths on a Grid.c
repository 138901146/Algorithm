#include<stdio.h>

int main(void)
{
	long long n, m;

	scanf("%lld%lld", &n, &m);

	while(n||m)
	{
		long long ans=1;

		if(m<n)
		{
			n+=m;
			m=n-m;
			n=n-m;
		}

		for(long long i=1;i<=n;++i)
		{
			ans*=n+m+1-i;
			ans/=i;
		}

		printf("%lld\n", ans);
		scanf("%lld%lld", &n, &m);
	}

	return 0;
}