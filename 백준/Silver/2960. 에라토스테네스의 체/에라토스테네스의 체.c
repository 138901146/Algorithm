#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, K;
	bool prime[1001];

	for(int i=1000;i;--i)
		prime[i]=true;

	scanf("%d%d", &N, &K);

	for(int i=2;i<=N;++i)
		if(prime[i])
			for(int j=i;j<=N;j+=i)
				if(prime[j])
				{
					--K;

					if(!K)
					{
						printf("%d", j);
						return 0;
					}

					prime[j]=false;
				}

	return 0;
}