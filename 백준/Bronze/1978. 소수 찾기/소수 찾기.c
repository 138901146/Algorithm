#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, number, count=0;
	bool prime[1001];

	for(int i=1000;i;--i)
		prime[i]=true;
	prime[0]=prime[1]=false;

	for(int i=2;i<32;++i)
		if(prime[i])
			for(int j=i<<1;j<1001;j+=i)
				prime[j]=false;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &number);
		count+=prime[number];
	}

	printf("%d", count);
	return 0;
}