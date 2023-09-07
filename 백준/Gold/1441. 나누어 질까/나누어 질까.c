#include<stdio.h>

unsigned long long L, R, A[18], select[18], answer=0;
int N;

unsigned long long gcd(unsigned long long x,unsigned long long y)
{
	unsigned long long temp;

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
	if(current==total)
	{
		unsigned long long lcm=1;

		for(int i=0;i<total;++i)
		{
			lcm/=gcd(lcm,select[i]);
			lcm*=select[i];
		}

		if(total&1)
		{
			answer-=L/lcm;
			answer+=R/lcm;
		}
		else
		{
			answer-=R/lcm;
			answer+=L/lcm;
		}

		return;
	}

	for(int i=index;i<N;++i)
	{
		select[current]=A[i];
		combination(current+1,i+1,total);
	}
}

int main(void)
{
	scanf("%d%llu%llu", &N, &L, &R);
	--L;

	for(int n=0;n<N;++n)
		scanf("%llu", &A[n]);

	for(int n=1;n<=N;++n)
		combination(0,0,n);

	printf("%llu", answer);
	return 0;
}