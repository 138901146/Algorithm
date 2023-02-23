#include<stdio.h>

int main(void)
{
	int N, P, X=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int mul=1, square;

		scanf("%d", &P);

		square=P%10;
		P/=10;

		for(int j=0;j<square;j++)
			mul*=P;

		X+=mul;
	}

	printf("%d\n", X);
	return 0;
}