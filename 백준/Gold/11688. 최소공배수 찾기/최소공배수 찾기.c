#include<stdio.h>

long long lcm(long long x,long long y)
{
	long long ans=x*y, temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(x%y!=0)
	{
		temp=x;
		x=y;
		y=temp%y;
	}

	return ans/y;
}

int main(void)
{
	long long a, b, L, ans=1;
	int count=0, prime[20][2]={0, };

	scanf("%lld%lld%lld", &a, &b, &L);

	a=lcm(a,b);
	if(a>L || L%a!=0)
	{
		printf("-1\n");
		return 0;
	}
	L/=a;

	b=a;
	if(b%2==0)
	{
		while(b%2==0)
		{
			prime[0][1]++;
			b/=2;
		}
		prime[count++][0]=2;
	}
	for(long long i=3;i*i<=b;i+=2)
		if(b%i==0)
		{
			while(b%i==0)
			{
				b/=i;
				prime[count][1]++;
			}
			prime[count++][0]=i;
		}
	if(b!=1)
	{
		prime[count][0]=b;
		prime[count++][1]=1;
	}

	for(int i=0;i<count;i++)
		if(L%prime[i][0]==0)
			for(int j=0;j<prime[i][1];j++)
				L*=prime[i][0];

	printf("%lld\n", L);
	return 0;
}