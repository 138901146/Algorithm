#include<stdio.h>

long long N, M, prime[10], select[10], answer=0;

long long gcd(long long x,long long y)
{
	long long temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

void combination(int current,int index)
{
	long long lcm=1;

	for(int i=0;i<current;++i)
	{
		lcm/=gcd(lcm,select[i]);
		lcm*=select[i];
	}

	if(current)
		answer+=current&1?M/lcm:-(M/lcm);

	if(current==N)
		return;

	for(int i=index;i<N;++i)
	{
		select[current]=prime[i];
		combination(current+1,i+1);
	}
}

int main(void)
{
	scanf("%lld%lld", &N, &M);

	for(int n=0;n<N;++n)
		scanf("%lld", &prime[n]);

	combination(0,0);

	printf("%lld", answer);
	return 0;
}