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

void divide(int N)
{
	for(int i=2;i<=N;i++)
		if(N%i==0)
			if(isPrime(i))
			{
				printf("%d\n", i);
				N/=i;
				i--;
			}
	if(N!=1)
		printf("%d\n", N);
}

int main(void) 
{
	int N;

	scanf("%d", &N);

	divide(N);

	return 0;
}