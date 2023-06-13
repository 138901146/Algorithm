#include<stdio.h>

int main(void)
{
	int n, m;
	long long x, two=0, five=0;

	scanf("%d%d", &n, &m);

	x=2;
	while(x<=n)
	{
		two+=n/x;
		x<<=1;
	}
	x=5;
	while(x<=n)
	{
		five+=n/x;
		x*=5;
	}

	x=2;
	while(x<=m)
	{
		two-=m/x;
		x<<=1;
	}
	x=5;
	while(x<=m)
	{
		five-=m/x;
		x*=5;
	}

	m=n-m;
	x=2;
	while(x<=m)
	{
		two-=m/x;
		x<<=1;
	}
	x=5;
	while(x<=m)
	{
		five-=m/x;
		x*=5;
	}

	printf("%lld\n", two<five?two:five);
	return 0;
}