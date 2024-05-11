#include<stdio.h>

long long gcd(long long x,long long y)
{
	while(y)
	{
		long long temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

long long lcm(long long x,long long y)
{
	return x/gcd(x,y)*y;
}

int main(void)
{
	long long D, P, Q, plus=0, min=2100000000;

	scanf("%lld%lld%lld", &D, &P, &Q);

	if(P<Q)
	{
		long long temp=P;
		P=Q;
		Q=temp;
	}

	if(362880<D/P)
	{
		long long lcm_value=lcm(P,Q);
		plus=D/lcm_value*lcm_value-lcm_value;
		D-=plus;
	}

	for(long long i=0;(i-1)*P<=D;++i)
	{
		long long left=D-i*P;

		if(left<=0)
		{
			if(i*P<min)
				min=i*P;
			break;
		}

		if(!(left%Q))
		{
			min=D;
			break;
		}

		if(((left/Q)+1)*Q+i*P<min)
			min=((left/Q)+1)*Q+i*P;
	}

	printf("%lld", min+plus);
	return 0;
}