#include<stdio.h>

int main(void)
{
	int N;
	long long A, sum=0, answer=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%lld", &A);
		answer+=((sum*A)%1000000007);
		answer%=1000000007;
		sum=(sum+A)%1000000007;
	}

	printf("%lld", answer);
	return 0;
}