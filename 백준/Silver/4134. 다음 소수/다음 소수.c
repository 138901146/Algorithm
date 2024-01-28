#include<stdio.h>

int is_prime(long long x)
{
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(!(x&1))
		return 0;
	for(long long i=3;i*i<=x;i+=2)
		if(!(x%i))
			return 0;
	return 1;
}

int main(void)
{
	long long tc, n;

	scanf("%lld", &tc);

	while(tc--)
	{
		scanf("%lld", &n);

		while(!is_prime(n))
			++n;

		printf("%lld\n", n);
	}

	return 0;
}