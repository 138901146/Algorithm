#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, prime_numbers[2000]={2}, count=1;
	bool prime[12000]={false};

	for(int i=11999;i>1;i-=2)
		prime[i]=true;

	scanf("%d", &N);

	for(int i=3;;i+=2)
		if(prime[i])
		{
			prime_numbers[count++]=i;

			if(N<prime_numbers[count-1]*prime_numbers[count-2])
			{
				printf("%d", prime_numbers[count-2]*prime_numbers[count-1]);
				return 0;
			}

			for(int j=i<<1;j<12000;j+=i)
				prime[j]=false;
		}

	return 0;
}