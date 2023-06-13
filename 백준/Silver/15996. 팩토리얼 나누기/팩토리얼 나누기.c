#include<stdio.h>

int main(void)
{
	int A, N;
	long long count=0;

	scanf("%d%d", &N, &A);

	if(A<=N)
	{
		long long k=A;
		while(k<=N)
		{
			count+=N/k;
			k*=A;
		}
	}

	printf("%lld\n", count);
	return 0;
}