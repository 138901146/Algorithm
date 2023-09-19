#include<stdio.h>

long long N, A[20], select[20], answer=0;
int K;

long long gcd(unsigned long long x,unsigned long long y)
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

void combination(int current,int index,int total)
{
	long long lcm=1;

	for(int i=0;i<current;++i)
	{
		lcm/=gcd(lcm,select[i]);
		lcm*=select[i];

		if(lcm>1000000000)
			break;
	}

	if(current && lcm<=1000000000)
	{
		if(current&1)
			answer+=N/lcm;
		else
			answer-=N/lcm;
	}

	if(current==total || lcm>1000000000)
		return;

	for(int i=index;i<K;++i)
	{
		select[current]=A[i];
		combination(current+1,i+1,total);
	}
}

int main(void)
{
	scanf("%lld%d", &N, &K);

	for(int i=0;i<K;++i)
		scanf("%lld", &A[i]);

	combination(0,0,K);

	printf("%lld", answer);
	return 0;
}