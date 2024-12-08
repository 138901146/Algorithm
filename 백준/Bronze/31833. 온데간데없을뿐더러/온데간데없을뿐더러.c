#include<stdio.h>

int main(void)
{
	int N;
	long long A, B, X=0, Y=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%lld", &A);

		B=A;

		while(B)
		{
			B/=10;
			X*=10;
		}

		X+=A;
	}

	for(int i=0;i<N;++i)
	{
		scanf("%lld", &B);

		A=B;

		while(A)
		{
			A/=10;
			Y*=10;
		}

		Y+=B;
	}

	printf("%lld", X<Y?X:Y);
	return 0;
}