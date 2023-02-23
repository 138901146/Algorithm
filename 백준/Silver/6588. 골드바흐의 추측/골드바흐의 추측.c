#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int n;
	bool is_prime[1000001]={false, false, true, };

	for(int i=2;i<1000001;i++)
		is_prime[i]=true;
	for(int i=2;i<1000001;i++)
		if(is_prime[i])
			for(int j=2*i;j<1000001;j+=i)
				is_prime[j]=false;

	scanf("%d", &n);

	while(n>0)
	{
		bool found=false;

		for(int i=3;i<=n/2;i+=2)
			if(is_prime[i] && is_prime[n-i])
			{
				printf("%d = %d + %d\n", n, i, n-i);
				found=true;
				break;
			}

		if(!found)
			printf("Goldbach's conjecture is wrong.\n");

		scanf("%d", &n);
	}

	return 0;
}