#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, two=0, five;

		scanf("%d", &N);

		five=N;
		while(five)
		{
			two+=five>>1;
			five>>=1;
		}

		five=0;
		while(N)
		{
			five+=N/5;
			N/=5;
		}

		printf("%d\n", two<five?two:five);
	}

	return 0;
}