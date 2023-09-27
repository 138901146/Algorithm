#include<stdio.h>

int main(void)
{
	long long n, x, sum=0, sigma=0;

	scanf("%lld", &n);

	while(n--)
	{
		scanf("%lld", &x);
		sigma+=sum*x;
		sum+=x;
	}

	printf("%lld", sigma);
	return 0;
}