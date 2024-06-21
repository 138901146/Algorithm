#include<stdio.h>

int main(void)
{
	long long n, CSOD=0;

	scanf("%lld", &n);

	for(int i=2;i<<1<=n;++i)
		CSOD=(CSOD+(long long)i*(n/i-1))%1000000;

	printf("%lld", CSOD);
	return 0;
}