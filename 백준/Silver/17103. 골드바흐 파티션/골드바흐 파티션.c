#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int T;
	bool sieve[1000001]={false, };

	for(int i=3;i<1000001;i+=2)
		sieve[i]=true;
	for(int i=3;i<1000001;i+=2)
		if(sieve[i])
			for(int j=2*i;j<1000001;j+=i)
				sieve[j]=false;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, count=0;

		scanf("%d", &N);

		for(int i=3;i*2<=N;i+=2)
			count+=sieve[i]&&sieve[N-i];

		printf("%d\n", N==4?1:count);
	}

	return 0;
}