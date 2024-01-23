#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int n;
	bool prime[1000001];

	for(int i=2;i<1000001;++i)
		prime[i]=true;
	prime[1]=false;

	for(int i=2;i<1001;++i)
		if(prime[i])
			for(int j=i<<1;j<1000001;j+=i)
				prime[j]=false;

	scanf("%d", &n);
	while(n)
	{
		bool found=false;

		for(int i=3;i<<1<=n && !found;i+=2)
			if(prime[i]&&prime[n-i])
			{
				printf("%d = %d + %d\n", n, i, n-i);
				found=true;
			}

		if(!found)
			printf("Goldbach's conjecture is wrong.\n");

		scanf("%d", &n);
	}

	return 0;
}