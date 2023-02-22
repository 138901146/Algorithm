#include<stdio.h>
#include<stdbool.h>

bool isPrime(int N)
{
	if(N<2)
		return false;
	else if(N==2)
		return true;
	else if(N%2==0)
		return false;
	else
		for(int i=3;i*i<=N;i+=2)
			if(N%i==0)
				return false;
	return true;
}

int main(void)
{
	int prime_count=1, prime[283146]={2, }, N, count=0;

	scanf("%d", &N);

	for(int i=3;i<=N;i+=2)
		if(isPrime(i))
			prime[prime_count++]=i;

	for(int i=0;i<prime_count;i++)
	{
		int sum=0;

		for(int j=0;sum<N;j++)
			sum+=prime[i+j];

		count+=sum==N;
	}

	printf("%d\n", count);

	return 0;
}