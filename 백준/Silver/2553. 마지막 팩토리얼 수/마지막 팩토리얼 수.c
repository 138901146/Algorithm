#include<stdio.h>

int main(void)
{
	int N;
	long long factorial=1;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
	{
		factorial%=100000000;
		factorial*=i;

		while(!(factorial%10))
			factorial/=10;
	}

	printf("%lld", factorial%10);
	return 0;
}