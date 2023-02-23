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
	int T, small, big, k;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d", &k);

		if(isPrime(k))
			printf("0\n");
		else
		{
			for(big=k+1;!isPrime(big);big++);
			for(small=k-1;small>0&&!isPrime(small);small--);

			printf("%d\n", small!=0?big-small:0);
		}
	}

	return 0;
}