#include<stdio.h>

int is_prime(long long x)
{
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(!(x&1))
		return 0;
	for(long long i=3;i*i<=x;i+=2)
		if(!(x%i))
			return 0;
	return 1;
}

int main(void)
{
	int map[10]={0,1,2,-1,-1,5,9,-1,8,6};
	long long N, temp, reversed=0;

	scanf("%lld", &N);

	temp=N;
	while(temp)
	{
		if(map[temp%10]==-1)
		{
			printf("no");
			return 0;
		}

		reversed*=10;
		reversed+=map[temp%10];

		temp/=10;
	}

	printf("%s", is_prime(N)&&is_prime(reversed)?"yes":"no");
	return 0;
}