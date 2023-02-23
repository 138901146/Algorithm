#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

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
	int test_case;

	scanf("%d", &test_case);

	for(int t=0;t<test_case;t++)
	{
		int N, *fac=NULL, temp;

		scanf("%d", &N);
		fac=(int *)calloc(N+1,sizeof(int));
		temp=N;

		for(temp=2;temp<=N;temp++)
			if(N%temp==0)
				if(isPrime(temp))
				{
					fac[temp]++;
					N/=temp;
					temp--;
				}
		if(N!=1)
			fac[N]++;

		for(int i=2;i<=temp;i++)
			if(fac[i]!=0)
				printf("%d %d\n", i, fac[i]);
		free(fac);
	}

	return 0;
}