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
		for(int n=3;n*n<=N;n+=2)
			if(N%n==0)
				return false;
	return true;
}

int main(void)
{
	int count=1, prime[167], T, K;

	prime[0]=2;
	for(int i=3;i<997;i+=2)
		if(isPrime(i))
			prime[count++]=i;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		bool solved=false;

		scanf("%d", &K);

		for(int i=0;prime[i]<K;i++)
		{
			for(int j=i;prime[i]+prime[j]<K;j++)
			{
				for(int k=j;prime[i]+prime[j]+prime[k]<=K;k++)
					if(prime[i]+prime[j]+prime[k]==K)
					{
						solved=true;
						printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					}
				if(solved)
					break;
			}
			if(solved)
				break;
		}

		if(!solved)
			printf("0\n");
	}

	return 0;
}