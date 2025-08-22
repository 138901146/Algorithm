#include<stdio.h>

int main(void)
{
	unsigned long long N, factorial=1;

	scanf("%llu", &N);

	for(long long n=2;n<=N;++n)
	{
		factorial*=n;
		while(!(factorial%10))
			factorial/=10;
		factorial%=1000000000000;
	}

	printf("%05llu", factorial%100000);
	return 0;
}