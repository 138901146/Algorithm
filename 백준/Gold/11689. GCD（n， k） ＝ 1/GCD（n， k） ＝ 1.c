#include<stdio.h>

int main(void)
{
	long long n, phi;

	scanf("%lld", &n);
	phi=n;

	for(long long i=2;i*i<=n;++i)
	{
		if(!(n%i))
			phi=phi/i*(i-1);
		while(!(n%i))
			n/=i;
	}

	printf("%lld", n==1?phi:phi/n*(n-1));
	return 0;
}