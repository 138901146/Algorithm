#include<stdio.h>

int isPrime(int N)
{
	if(N<2)
		return 0;
	else if(N==2)
		return 1;
	else if(N%2==0)
		return 0;
	for(int i=3;i*i<=N;i+=2)
		if(N%i==0)
			return 0;
	return 1;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int n;

		scanf("%d", &n);

		for(int j=n/2;j>=2;j--)
			if(isPrime(j)&&isPrime(n-j))
			{
				printf("%d %d\n", j, n-j);
				break;
			}
	}

	return 0;
}