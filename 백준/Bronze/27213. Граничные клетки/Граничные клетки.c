#include<stdio.h>

long long max(long long x,long long y)
{
	return x<y?y:x;
}

int main(void)
{
	long long m, n;

	scanf("%lld", &m);
	scanf("%lld", &n);

	printf("%lld", m*n-max(m-2,0)*max(n-2,0));
	return 0;
}