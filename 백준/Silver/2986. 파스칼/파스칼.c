#include<stdio.h>
#include<stdbool.h>

int isPrime(int N)
{
	if(N<2)
		return false;
	else if(N==2)
		return true;
	else if(N%2==0)
		return false;
	else
		for(int n=3;n*n<=N;n++)
			if(N%n==0)
				return false;
	return true;
}

int main(void)
{
	int N, counter=0;

	scanf("%d", &N);

	if(isPrime(N))
		counter=N-1;
	else if(N%2==0)
		counter=N/2;
	else
	{
		for(int i=3;i<=N;i+=2)
			if(N%i==0)
			{
				counter=N-N/i;
				break;
			}
	}

	printf("%d\n", counter);
	return 0;
}