#include<stdio.h>

int isPrime(int N)
{
	if(N<2)
		return 0;
	else if(N==2)
		return 1;
	else if(N%2==0)
		return 0;
	else
		for(int i=3;i*i<=N;i+=2)
			if(N%i==0)
				return 0;
	return 1;
}

int main(void)
{
	int M, N, sum=0, min=-1;

	scanf("%d", &M);
	scanf("%d", &N);

	for(int i=N;i>=M;i--)
		if(isPrime(i))
		{
			min=i;
			sum+=i;
		}

	if(min!=-1)
		printf("%d\n", sum);
		printf("%d\n", min);

	return 0;
}