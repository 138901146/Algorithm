#include<stdio.h>

int is_prime(int x)
{
	if(x==2)
		return 1;
	else if(x<2)
		return -1;
	else if(!(x&1))
		return -1;
	for(int i=3;i*i<=x;++i)
		if(x%i==0)
			return -1;
	return 1;
}

int main(void)
{
	int prime[10001]={0}, test_case, P, M;

	scanf("%d", &P);

	while(P--)
	{
		scanf("%d%d", &test_case, &M);

		if(prime[M]==0)
		{
			prime[M]=is_prime(M);

			if(prime[M]==1)
			{
				int temp=M;

				for(int i=0;i<100&&temp!=1;++i)
				{
					int sum=0;

					while(temp)
					{
						sum+=(temp%10)*(temp%10);
						temp/=10;
					}

					temp=sum;
				}

				if(temp!=1)
					prime[M]=-1;
			}
		}

		printf("%d %d %s\n", test_case, M, prime[M]<0?"NO":"YES");
	}

	return 0;
}