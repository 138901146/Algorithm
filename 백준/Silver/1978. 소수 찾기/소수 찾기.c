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
		for(int i=2;i*i<=N;i++)
			if(N%i==0)
				return 0;
	return 1;
}

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int num;

	scanf("%d", &num);

	count+=isPrime(num);
	}

	printf("%d\n", count);

	return 0;
}