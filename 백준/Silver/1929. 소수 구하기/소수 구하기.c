#include<stdio.h>

int isPrime(int N)
{
	if(N==2)
		return 1;
	else if(N==1 || N%2==0)
		return 0;
	for(int i=3;i*i<=N;i+=2)
		if(N%i==0)
			return 0;
	return 1;
}

int main(void)
{
	int M, N;

	scanf("%d %d", &M, &N);

	for(int i=M;i<=N;i++)
		if(isPrime(i))
			printf("%d\n", i);

	return 0;
}