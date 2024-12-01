#include<stdio.h>

int main(void)
{
	int Q, a, m;

	scanf("%d", &Q);

	while(Q--)
	{
		double price=1.76;

		scanf("%d%d", &a, &m);

		price*=m;
		price*=a;
		price/=1000.0;
		printf("%lld\n", (long long)price);
	}

	return 0;
}