#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		unsigned long long n, max;

		scanf("%llu", &n);
		max=n;

		while(n!=1)
		{
			if(n&1)
				n=n*3+1;
			else
				n>>=1;
			max=n<max?max:n;
		}

		printf("%llu\n", max);
	}

	return 0;
}